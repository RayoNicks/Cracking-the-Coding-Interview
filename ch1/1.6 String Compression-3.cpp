class Solution {
public:
    string compressString(string S) {
        size_t cprLen = cntCompression(S);
        if(cprLen >= S.size()) return S;
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
        return oss.str();
    }
private:
    size_t cntCompression(const string &S)
    {
        size_t ret = 0;
        int iCnt = 0;
        for(size_t i = 0; i < S.size(); i++)
        {
            iCnt++;
            if(i == S.size() - 1 || S[i] != S[i + 1]){
                ret++;
                ret += to_string(iCnt).size();
                iCnt = 0;
            }
        }
        return ret;
    }
};
