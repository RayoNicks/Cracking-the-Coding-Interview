class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        enumSubset(nums, nums.size());
        return Subset;
    }
private:
    vector<vector<int>> Subset;
    void enumSubset(const vector<int> &nums, size_t size)
    {
        if(size == 0){
            Subset.push_back(vector<int>());
            return;
        }
        enumSubset(nums, size - 1);
        size_t cnt = Subset.size();
        for(size_t idx = 0; idx != cnt; idx++)
        {
            Subset.push_back(Subset[idx]);
            Subset.back().push_back(nums[size - 1]);
        }
        return;
    }
};
