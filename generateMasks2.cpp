#include <iostream>

using namespace std;

// generate master bitmask string for ith mask (i.e. one that is the maximum size possible)
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
/*
    // print for testing
    void print() const {
    for (int j=0; j<max_num_bits; j++)
      cout << str[j];
    cout << endl;
    }
*/
};


int main() {
    constexpr unsigned int max_num_bits = 128;
    constexpr Bitmask_i bitmask0 = Bitmask_i<max_num_bits, 1>();
    constexpr Bitmask_i bitmask1 = Bitmask_i<max_num_bits, 2>();
    constexpr Bitmask_i bitmask2 = Bitmask_i<max_num_bits, 4>();
    constexpr Bitmask_i bitmask3 = Bitmask_i<max_num_bits, 8>();
    constexpr Bitmask_i bitmask4 = Bitmask_i<max_num_bits, 16>();
    constexpr Bitmask_i bitmask5 = Bitmask_i<max_num_bits, 32>();
    constexpr Bitmask_i bitmask6 = Bitmask_i<max_num_bits, 64>();
    constexpr Bitmask_i bitmask7 = Bitmask_i<max_num_bits, 128>();

    /*
    bitmask1.print();
    bitmask2.print();
    bitmask3.print();
    bitmask4.print();
    bitmask5.print();
    bitmask7.print();
    */

    cout << bitmask1.str << endl;;
    cout << bitmask2.str << endl;;
    cout << bitmask3.str << endl;;
    cout << bitmask4.str << endl;;
    cout << bitmask5.str << endl;;
    cout << bitmask6.str << endl;;
    cout << bitmask7.str << endl;;
    return 0;
}

