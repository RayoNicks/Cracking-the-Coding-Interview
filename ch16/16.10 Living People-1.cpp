class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int maxLive = 0, maxYear = 1900, live;
        for(int year = 1900; year <= 2000; year++)
        {
            live = 0;
            for(size_t p = 0; p < birth.size(); p++)
            {
                if(birth[p] <= year && year <= death[p]){
                    live++;
                }
            }
            if(live > maxLive){
                maxLive = live;
                maxYear = year;
            }
        }
        return maxYear;
    }
};
