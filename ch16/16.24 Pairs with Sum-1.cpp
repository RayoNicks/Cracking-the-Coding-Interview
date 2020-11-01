class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        map<int, size_t> Remain;
        for_each(nums.begin(), nums.end(),
            [&Remain](const int i)
            {
                Remain[i]++;
            });
        for(auto i : nums)
        {
            size_t &cnt1 = Remain[i], &cnt2 = Remain[target - i];
            if(cnt1 != 0){
                cnt1--;
                if(cnt2 != 0){
                    ret.emplace_back(1, i);
                    ret.back().push_back(target - i);
                    cnt2--;
                }
                else cnt1++;
            }
        }
        return ret;
    }
};
