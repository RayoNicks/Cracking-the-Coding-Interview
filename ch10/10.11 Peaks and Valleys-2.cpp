class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int tmp;
        for(size_t i = 1; i < nums.size(); i += 2)
        {
            size_t idx = smallIdx(nums, i - 1, i, i + 1);
            if(idx != i){
                tmp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = tmp;
            }
        }
    }
private:
    size_t smallIdx(const vector<int> &nums, size_t left, size_t mid, size_t right)
    {
        size_t ret = nums[left] < nums[mid] ? left : mid;
        if(right < nums.size()){
            ret = nums[ret] < nums[right] ? ret : right;
        }
        return ret;
    }
};
