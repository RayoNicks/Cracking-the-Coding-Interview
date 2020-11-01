class Solution {
private:
    void swap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
public:
    vector<int> missingTwo(vector<int>& nums) {
        nums.push_back(0);
        nums.push_back(0);
        for(int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            while(nums[i] != 0 && nums[i] != i + 1){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ret;
        for(int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            if(nums[i] == 0) ret.push_back(i + 1);
        }
        return ret;
    }
};
