class Solution {
private:
    int missingNumber(const vector<bitset<32>> &input, int column)
    {
        if(column >= 32) return 0;
        vector<bitset<32>> Zeros, Ones;
        for(auto bs : input)
        {
            if(bs.test(column)) Ones.push_back(bs);
            else Zeros.push_back(bs);
        }
        if(Zeros.size() <= Ones.size()){
            int v = missingNumber(Zeros, column + 1);
            return (v << 1) | 0;
        }
        else{
            int v = missingNumber(Ones, column + 1);
            return (v << 1) | 1;
        }
    }
public:
    int missingNumber(vector<int>& nums) {
        vector<bitset<32>> input;
        for(int i : nums)
        {
            input.push_back(bitset<32>(i));
        }
        return missingNumber(input, 0);
    }
};
