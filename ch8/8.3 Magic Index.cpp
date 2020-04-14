class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return MagicIndex(nums, 0, nums.size());
    }
private:
    int MagicIndex(const vector<int> &nums, int b, int e)
    {
        int mid = b + (e - b) / 2, ret;
        if(b >= e) return -1;
        //int end = mid <= nums[mid] ? mid : mid;
        ret = MagicIndex(nums, b, mid);
        if(ret != -1) return ret;
        else if(mid == nums[mid]) return mid;
        else{
            int begin = mid < nums[mid] ? nums[mid] : mid + 1;
            return MagicIndex(nums, begin, e);
        }
    }
};
