class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        map<int, size_t> SmallCount;
        for(int s : small)
        {
            SmallCount[s] = 0;
        }
        size_t count = SmallCount.size(), left = 0, right = 0;
        for(right = 0; right < big.size(); right++)
        {
            auto iter = SmallCount.find(big[right]);
            if(iter != SmallCount.end()){
                iter->second++;
                if(iter->second == 1) count--;
                if(count == 0) break;
            }
        }
        if(count != 0) return {};
        size_t i = left, j = right;
        while(j < big.size()){
            for(; i < big.size(); i++)
            {
                auto iter = SmallCount.find(big[i]);
                if(iter != SmallCount.end()){
                    iter->second--;
                    if(iter->second == 0) break;
                }
            }
            if(j - i < right - left){
                left = i;
                right = j;
            }
            for(i = i + 1, j = j + 1; j < big.size(); j++)
            {
                auto iter = SmallCount.find(big[j]);
                if(iter != SmallCount.end()){
                    iter->second++;
                    if(iter->second == 1) break;
                }
            }
            if(j - i < right - left){
                left = i;
                right = j;
            }
        }
        return { static_cast<int>(left), static_cast<int>(right) };
    }
};
