class Solution {
public:
    int exchangeBits(int num) {
        unsigned int n = num;
        return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    }
};
