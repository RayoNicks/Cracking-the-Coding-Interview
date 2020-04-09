class Solution {
public:
    int reverseBits(int num) {
        calSeqLength(num);
        int ret = 0;
        for(size_t i = 0; i < vecSeqLen.size(); i += 2)
        {
            int left = i >= 1 ? vecSeqLen[i - 1] : 0;
            int right = i + 1 < vecSeqLen.size() ? vecSeqLen[i + 1] : 0;
            int total;
            if(vecSeqLen[i] == 1) total = left + right + 1;
            else {
                if(left > right) total = left + 1;
                else total = right + 1;
            }
            if(total > ret) ret = total;
        }
        return ret;
    }
private:
    vector<int> vecSeqLen;
    void calSeqLength(int num)
    {   
        bool bSearch = false;
        int cnt = 0;
        for(int idx = 0; idx < sizeof(decltype(num)) * 8; idx++)
        {
            if((num & 0x1) != bSearch){
                vecSeqLen.push_back(cnt);
                bSearch = !bSearch;
                cnt = 0;
            }
            cnt++;
            num >>= 1;
        }
        vecSeqLen.push_back(cnt);
    }
};
