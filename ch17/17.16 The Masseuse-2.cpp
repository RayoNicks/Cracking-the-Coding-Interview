class Solution {
public:
    int massage(vector<int>& nums) {
        vector<int> Minutes = { 0, 0 };
        for(size_t i = 0; i < nums.size(); i++)
        {
            Minutes.push_back(max(Minutes[i] + nums[i], Minutes[i + 1]));
        }
        return Minutes.back();
    }
};
