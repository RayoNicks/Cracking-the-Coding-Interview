class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, count = 0;
        for(int n : nums)
        {
            if(count == 0) major = n;
            if(n == major) count++;
            else count--;
        }
        count = 0;
        for(int n : nums)
        {
            if(n == major) count++;
        }
        if(count * 2 > nums.size()) return major;
        else return -1;
    }
};
