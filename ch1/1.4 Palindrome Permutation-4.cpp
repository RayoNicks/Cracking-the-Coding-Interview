class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> bits;
        for(auto c : s)
        {
            bits.flip(c);
        }
        return bits.count() <= 1;
    }
};
