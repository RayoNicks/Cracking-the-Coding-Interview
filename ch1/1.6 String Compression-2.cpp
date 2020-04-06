class Solution {
public:
    string compressString(string S) {
        ostringstream oss;
        int iCnt = 0;
        for(size_t i = 0; i < S.size(); i++)
        {
            iCnt++;
            if(i == S.size() - 1 || S[i] != S[i + 1]){
                oss << S[i] << iCnt;
                iCnt = 0;
            }
        }
        if(oss.str().size() < S.size()) return oss.str();
        else return S;
    }
};
