class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int iCnt[128] = {0};
        for(auto c : s1)
        {
            iCnt[c]++;
        }
        for(auto c : s2)
        {
            iCnt[c]--;
            if(iCnt[c] < 0) return false;
        }
        return true;
    }
};
