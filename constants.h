// constants and typedefs

// used for generating masks, and sizing bitsets (BitVectors)
constexpr unsigned int num_variables = 8;
constexpr unsigned int num_bits = 1<<num_variables;    // 2^num_variables

// bitset of size max_num_bits we shall call BitVector
typedef std::bitset<num_bits> BitVector;
