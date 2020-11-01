class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        sort(birth.begin(), birth.end());
        sort(death.begin(), death.end());
        size_t birthIdx = 0, deathIdx = 0;
        int currLive = 0, maxLive = 0, maxYear;
        while(birthIdx != birth.size()){
            if(birth[birthIdx] <= death[deathIdx]){
                currLive++;
                if(currLive > maxLive){
                    maxLive = currLive;
                    maxYear = birth[birthIdx];
                }
                birthIdx++;
            }
            else{
                currLive--;
                deathIdx++;
            }
        }
        return maxYear;
    }
};
