#include <iostream>
#include "constants.h"


class Masks {

    // generate string for initialising ith bitmask, and write to string str
    // note that num_variables+1 bytes should be allocated for str (i.e. len is known)
    static char *BitMask_i_string(unsigned int i, char *str) {
        unsigned int k = 2<<i;

        // iterate bit by bit, setting relevant bits for ith mask high
        for (int j=0; j<num_bits; j++) {
            if ((j%k) >= (k>>1)) {
                str[j] = '0';
            } else {
                str[j] = '1';
            }
        }
        // add null terminator and return string pointer
        str[num_bits] = '\0';
        return str;
    }

public:
    BitVector arr[num_variables];

    Masks() {
        for (int i=0; i<num_variables; i++) {
            char str[num_bits+1];
            arr[i] = BitVector(BitMask_i_string(i, str));
        }
    }
};

int main() {
    Masks masks;
    std::cout << masks.arr[1] << std::endl;
    return 0;
}
