class Solution {
private:
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
        vector<int> vecDelta(2000 - 1900 + 2, 0);
        for(size_t idx = 0; idx < birth.size(); idx++)
        {
            vecDelta[year2idx(birth[idx])]++;
            vecDelta[year2idx(death[idx]) + 1]--;
        }
        int currLive = 0, maxLive = 0, maxYear;
        for(size_t idx = 0; idx < vecDelta.size(); idx++)
        {
            currLive += vecDelta[idx];
            if(currLive > maxLive){
                maxLive = currLive;
                maxYear = idx2year(idx);
            }
        }
        return maxYear;
    }
};
