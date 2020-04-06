class Solution {
public:
    bool canPermutePalindrome(string s) {
        int iSet = 0;
        for(auto c : s)
        {
            iSet ^= 1 << (tolower(c) - 'a');
        }
        return !(iSet & (iSet - 1));
    }
};
