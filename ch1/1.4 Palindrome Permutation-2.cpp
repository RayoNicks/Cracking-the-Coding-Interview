class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[128] = { 0 }, cOdd = 0;
        for(auto c : s)
        {
            cnt[c]++;
            if(cnt[c] & 0x1 == 1) cOdd++;
            else cOdd--;
        }
        return cOdd <= 1;
    }
};
