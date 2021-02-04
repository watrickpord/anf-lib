#include <iostream>
#include <utility>
#include "constants.h"
#include "Masks.h"

// masks class instance looks like array of pointers to msx masks
Masks mask_ptrs;

class Zpoly {
    // for a given bit index (i.e. 0 to num_bits), return the string for the
    // term (e.g. abc) that bit refers to
    static std::string termAtBitIndex(unsigned int bit_index) {
        if (bit_index == 0) {
            return "1";
        } else {
            BitVector bit = 1<<bit_index;
            std::string term_string = "";

            for (int i=0; i<num_variables; i++) {
                // if bit has variable i in it, anding with that mask will leave it
                // unchanged, while if that variable is not in term at bit, it will
                // go to zero
                if ((bit & *mask_ptrs[i]) == bit)
                    term_string = term_string + variable_symbols[i];
            }
            return term_string;
        }
    }

    // method to return this multiplied by a single variable (e.g. 0 = a, 1=b etc.)
    Zpoly multiplyByVariable(const unsigned int variable_index) const {
        // mask-shift
        Zpoly mask_shifted = (*this)<<(variable_index+1);
        // xor
        BitVector unmask_shifted = *mask_ptrs[variable_index] & value;
        return Zpoly(mask_shifted.value ^ unmask_shifted);
    }


public:
    Zpoly(int val_in) {
        value = (BitVector)val_in;
    }

    Zpoly(BitVector val_in) {
        value = val_in;
    }

    // TODO: init polynomial from string constructor

    // public variables
    BitVector value;
    static std::string variable_symbols[num_variables];

    // return string representation of polynomial (ie. 1 + a + b + ab ...)
    std::string toString () const {
        if (value == 0) {
            return "0";
        } else {
            // iterate bit by bit, adding termAtBitIndex whenever bit is 1
            std::string polynomial_string = "";
            for (int i=0; i<num_bits; i++) {
                if (value.test(i)) {
                    polynomial_string = polynomial_string + " + " + termAtBitIndex(i);
                }
            }
            // remove leading (extraneous) plus and return
            return polynomial_string.substr(3, polynomial_string.size());
        }
    }

    // add two polynomials (xor their bits together)
    Zpoly operator+(const Zpoly& other) const {
        return Zpoly(value ^ other.value);
    }

    // left and right shifts are defined as mask shifts, going left uses inverse
    // of mask (i.e. to be used in multiplication algorithm),
    // right shift uses mask (i.e. corrosponds to differentiation by variable)
    Zpoly operator<<(const unsigned int& shift_amt) const {
      if (shift_amt == 0) {
          return *this;
      } else {
          BitVector mask = ~(*mask_ptrs[shift_amt-1]);
          BitVector masked = mask & value;
          BitVector shifted = masked << shift_amt;
          return Zpoly(shifted);
      }
    }

    // note this operator corrosponds exactly to derivative by symbol at shift_amt-1
    Zpoly operator>>(const unsigned int& shift_amt) const {
      if (shift_amt == 0) {
          return *this;
      } else {
          BitVector mask = *mask_ptrs[shift_amt-1];
          BitVector masked = mask & value;
          BitVector shifted = masked >> shift_amt;
          return Zpoly(shifted);
      }
    }


    // multiplication uses mask-shift-xor algo (using already defined mask-shifts)
    Zpoly operator*(const Zpoly& other) const {
        // let self be the multiplier and other be the multiplicand
        // thus we iterate bit by bit though self, and if the bit is high
        // apply msx's for that variable
        Zpoly result_accumulator(0);
        for (int bit_index=0; bit_index<num_bits; bit_index++) {
            if (value[bit_index]) {
                // we need to express each term as a individual variables, e.g.
                // abc = a,b,c <- we do msx multiplication for each of these
                std::bitset<num_variables> pow_2_sum_list(bit_index);
                Zpoly term_times_multiplicand(other.value);
                for (int variable_index = 0; variable_index<num_variables; variable_index++) {
                    if (pow_2_sum_list[variable_index])
                        term_times_multiplicand = term_times_multiplicand.multiplyByVariable(variable_index);
                }
                // add the current term (e.g. abc*(other) ) to the accumulator
                result_accumulator = result_accumulator + term_times_multiplicand;
            }
        }
        return result_accumulator;
    }
};

std::string Zpoly::variable_symbols[num_variables] = {"a", "b", "c"};

int main() {
    for(int i=0; i<(1<<num_bits); i++) {
        Zpoly myp(i);
        std::cout << "Multiplicand: " << myp.toString() << std::endl;
        std::cout << "Multiplied  : " << ((myp*Zpoly(3)).toString()) << std::endl;
    }

    return 0;
}
