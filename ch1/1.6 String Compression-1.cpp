class Solution {
public:
    string compressString(string S) {
        string strCpr;
        int iCnt = 0;
        for(size_t i = 0; i < S.size(); i++)
        {
            iCnt++;
            if(i == S.size() - 1 || S[i] != S[i + 1]){
                strCpr += S[i] + to_string(iCnt);
                iCnt = 0;
            }
        }
        if(strCpr.size() < S.size()) return strCpr;
        else return S;
    }
};
