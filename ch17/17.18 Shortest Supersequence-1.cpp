class Solution {
private:
    vector<vector<int>> Table;
    void buildTable(const vector<int> &big, const vector<int> &small)
    {
        Table.assign(big.size(), vector<int>(small.size(), big.size()));
        for(size_t i = 0; i < small.size(); i++)
        {
            size_t closestIdx = big.size();
            for(size_t j = big.size(); j > 0; j--)
            {
                if(big[j - 1] == small[i]) closestIdx = j - 1;
                Table[j - 1][i] = closestIdx;
            }
        }
    }
    vector<int> findShortestRange()
    {
        int left = 0, right = Table.size();
        for(size_t i = 0; i < Table.size(); i++)
        {
            size_t start = i;
            size_t max = i;
            for(size_t j = 0; j < Table[0].size(); j++)
            {
                if(max < Table[i][j]) max = Table[i][j];
            }
            if(max != Table.size() && max - start < right - left){
                left = start;
                right = max;
            }
        }
        if(right == Table.size()) return {};
        return { left, right };
    }
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        buildTable(big, small);
        return findShortestRange();
    }
};
