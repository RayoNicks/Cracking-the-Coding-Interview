class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        unsigned long long mask = ULLONG_MAX << (j + 1);
        mask ^= (1 << i) - 1;
        N &= (unsigned int)mask;
        M <<= i;
        return N | M;
    }
};
