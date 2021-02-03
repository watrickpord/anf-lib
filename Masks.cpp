
#include "Masks.h"

#include <iostream>

// generate string for initialising ith bitmask, and write to string str
// note that num_variables+1 bytes should be allocated for str (i.e. len is known)
char *Masks::BitMask_i_string(unsigned int i, char *str) {
    // we want masks for k=1,2,4,8...
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

// init masks in constructor
Masks::Masks() {
    for (int i=0; i<num_variables; i++) {
        // get string for ith bitmask and init ith BitVector with it
        char str[num_bits+1];
        arr[i] = BitVector(BitMask_i_string(i, str));
    }
}

// retrieve ith mask's BitVector (returns pointer to it)
const BitVector *Masks::operator[](unsigned int i) {
    if (i >= num_variables) {
        std::cerr << "Error: variable index out of bounds";
        return NULL;
    }
    return (arr+i);
}
