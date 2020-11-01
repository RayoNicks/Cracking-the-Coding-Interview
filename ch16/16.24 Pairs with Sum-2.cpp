class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        auto iter = nums.begin();
        auto riter = nums.rbegin();
        while(iter + 1 < riter.base()){
            int sum = *iter + *riter;
            if(sum < target) iter++;
            else if(sum > target) riter++;
            else{
                ret.push_back(vector<int>());
                ret.back().push_back(*iter);
                ret.back().push_back(*riter);
                iter++, riter++;
            }
        }
        return ret;
    }
};
