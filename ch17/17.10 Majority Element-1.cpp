class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, size_t> Freq;
        for(int n : nums)
        {
            Freq[n]++;
        }
        for(auto p : Freq)
        {
            if(p.second * 2 > nums.size()) return p.first;
        }
        return -1;
    }
};
