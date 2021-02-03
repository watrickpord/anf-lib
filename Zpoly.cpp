#include <iostream>
#include <utility>
#include <array>

// used for generating master masks (i.e. largest posssible) at compile time
constexpr unsigned int max_num_variables = 8;
constexpr unsigned int max_num_bits = 1<<max_num_variables;    // 2^num_variables

// bitset of size max_num_bits we shall call BitVector
typedef std::bitset<max_num_bits> BitVector;


// generate bitmask string for ith mask (i.e. one that is the maximum size possible)
template<unsigned int max_num_bits, unsigned int i>
struct Bitmask_i {
    char str[max_num_bits+1];

    // constexpr array constructor
    constexpr Bitmask_i() : str() {
        // iterate bit by bit, setting relevant bits for ith mask high
        for (int j=0; j<max_num_bits; j++) {
            if ((j%(i)) >= ((i)>>1)) {
                str[j] = '0';
            } else {
                str[j] = '1';
            }
        }
        // add null terminator
        str[max_num_bits] = '\0';
    }
};


// TODO: generate array of bitmask objects...
// probably put into templated struct with operator overloading on [], and  constructor
// see https://stackoverflow.com/questions/2978259/programmatically-create-static-arrays-at-compile-time-in-c






int main() {
    constexpr Bitmask_i bitmask0 = Bitmask_i<max_num_bits, 1>();
    constexpr Bitmask_i bitmask1 = Bitmask_i<max_num_bits, 2>();
    constexpr Bitmask_i bitmask2 = Bitmask_i<max_num_bits, 4>();
    constexpr Bitmask_i bitmask3 = Bitmask_i<max_num_bits, 8>();
    constexpr Bitmask_i bitmask4 = Bitmask_i<max_num_bits, 16>();
    constexpr Bitmask_i bitmask5 = Bitmask_i<max_num_bits, 32>();
    constexpr Bitmask_i bitmask6 = Bitmask_i<max_num_bits, 64>();
    constexpr Bitmask_i bitmask7 = Bitmask_i<max_num_bits, 128>();

    BitVector bv1 = BitVector(bitmask3.str);
    std::cout << bv1 << std::endl;

    return 0;
}
