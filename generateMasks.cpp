#include <iostream>


using namespace std;

const unsigned int num_bits = 64;
/*
template<int n>
struct MagicNum {
    enum {
        value = ((1<<n)-1 + MagicNum<n-1>::value)<<(1<<n)
    };
};

template<>
struct MagicNum<0> {
    enum { value = 2};
};

template<int n, int iters, int total_iters>
struct MaskGen {
    enum {
        value =(MaskGen<n, iters-1, total_iters>::value<<(2<<(total_iters-iters))) | MaskGen<n, iters-1, total_iters>::value
    };
};

template<int n, int total_iters>
struct MaskGen<n, 0, total_iters> {
    enum {
        value = MagicNum<n>::value
    };
};*/
/*
template<unsigned int mask_num, unsigned int bit_index>
struct MaskGen {
    enum {
        value = MaskGen<mask_num, bit_index-1>::value | ((bit_index%mask_num >= (mask_num>>1))<<bit_index)
    };
};

template<unsigned int mask_num>
struct MaskGen<mask_num, 0> {
    enum {
        value = 0
    };
};
*/
/*
template<unsigned long long int mask_num, unsigned long long int bit_index>
struct MaskGen {
    static const unsigned long long int value = MaskGen<mask_num, bit_index-1>::value | ((bit_index%mask_num >= (mask_num>>1))<<bit_index);
};

template<unsigned long long int mask_num>
struct MaskGen<mask_num, 0> {
    static const unsigned long long int value = 0;
};
*/
template<unsigned long long int mask_num, unsigned long long int bit_index>
struct MaskGen {
    static const unsigned long long int value = MaskGen<mask_num, bit_index-1>::value | ((bit_index%mask_num >= (mask_num>>1))<<bit_index);
};

template<unsigned long long int mask_num>
struct MaskGen<mask_num, 0> {
    static const unsigned long long int value = 0;
};


int main() {
    //cout << bitset<16>(MaskGen<0,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<1,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<2,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<3,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<4,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<5,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<6,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<7,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<8,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<9,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<10,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<11,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<12,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<13,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<14,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<15,num_bits>::value) << endl;
    cout << bitset<num_bits>(MaskGen<16,num_bits>::value) << endl;

    // note - for our masks we just want the powers of two, exculding 1, pattern
    // looks nice though

}
