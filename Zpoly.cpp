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

public:
    Zpoly(int val_in) {
        value = (BitVector)val_in;
    }


    BitVector value;
    static std::string variable_symbols[num_variables];

    std::string toString () {
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
};

std::string Zpoly::variable_symbols[num_variables] = {"a", "b", "c"};

int main() {
    for(int i=0; i<(1<<num_bits); i++) {
        Zpoly myp(i);
        std::cout << myp.value << std::endl;
        std::cout << myp.toString() << std::endl;
    }

    return 0;
}
