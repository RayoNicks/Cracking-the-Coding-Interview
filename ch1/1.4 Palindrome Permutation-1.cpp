class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[128] = { 0 };
        for(auto c : s)
        {
            cnt[c]++;
        }
        bool bOdd = false;
        for(int i = 0; i < 128; i++)
        {
            if(cnt[i] & 0x1 == 1){
                if(!bOdd) bOdd = true;
                else return false;
            }
        }
        return true;
    }
};
