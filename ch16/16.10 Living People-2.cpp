class Solution {
private:
    vector<int> vecLive;
    int year2idx(const int year)
    {
        return year - 1900;
    }
    int idx2year(const int idx)
    {
        return idx + 1900;
    }
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vecLive.assign(2000 - 1900 + 1, 0);
        for(size_t p = 0; p < birth.size(); p++)
        {
            for(int year = birth[p]; year<= death[p]; year++)
            {
                vecLive[year2idx(year)]++;
            }
        }
        int maxLive = 0, maxYear;
        for(size_t idx = 0; idx < vecLive.size(); idx++)
        {
            if(vecLive[idx] > maxLive){
                maxLive = vecLive[idx];
                maxYear = idx2year(idx);
            }
        }
        return maxYear;
    }
};
