class Solution {
private:
    vector<int> BuildAndFind(const vector<int> &big, const vector<int> &small)
    {
        vector<int> Table(big.size(), -1);
        const int MAX = static_cast<int>(big.size());
        for(size_t i = 0; i < small.size(); i++)
        {
            size_t closestIdx = big.size();
            for(size_t j = big.size(); j > 0; j--)
            {
                if(big[j - 1] == small[i]) closestIdx = j - 1;
                if(Table[j - 1] == -1 || (Table[j - 1] < closestIdx)){
                    Table[j - 1] = closestIdx;
                }
            }
        }
        int left = 0, right = MAX;
        for(int i = 0; i < Table.size(); i++)
        {
            if(Table[i] != MAX && Table[i] - i < right - left){
                left = i;
                right = Table[i];
            }
        }
        if(right != MAX) return { left, right };
        else return {};
    }
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        return BuildAndFind(big, small);
    }
};
