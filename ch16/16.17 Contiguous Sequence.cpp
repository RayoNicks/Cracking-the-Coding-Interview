class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return INT_MIN;
        int sum = 0, max = INT_MIN;
        for(auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            sum += *iter;
            if(sum > max) max = sum;
            if(sum < 0) sum = 0;
        }
        return max;
    }
};
