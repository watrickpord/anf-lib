// Masks class header

#ifndef MASKS_H
#define MASKS_H

#include "constants.h"

class Masks {
    // interal array of bitmasks
    BitVector arr[num_variables];

    // generate string for initialising ith bitmask, and write to string str
    // note that num_variables+1 bytes should be allocated for str (i.e. len is known)
    static char *BitMask_i_string(unsigned int i, char *str);

public:
    // constructor inits masks
    Masks();

    // retrieve ith mask's BitVector (returns pointer to it)
    const BitVector *operator[](unsigned int i);

};

#endif
