class Solution {
private:
    vector<int> Memory;
    int massage(const vector<int> &nums, size_t curr)
    {
        if(curr >= nums.size()) return 0;
        if(Memory[curr] != -1) return Memory[curr];
        int BestWith = nums[curr] + massage(nums, curr + 2);
        int BestWithOut = massage(nums, curr + 1);
        Memory[curr] = max(BestWith, BestWithOut);
        return Memory[curr];
    }
public:
    int massage(vector<int>& nums) {
        Memory.assign(nums.size(), -1);
        return massage(nums, 0);
    }
};
