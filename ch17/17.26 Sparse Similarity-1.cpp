class Solution {
private:
    unordered_map<int, vector<size_t>> InvertedIndex;
    void createInvertedIndex(const vector<vector<int>> &docs)
    {
        for(size_t i = 0; i < docs.size(); i++)
        {
            const vector<int> &doc = docs[i];
            for(int n : doc)
            {
                InvertedIndex[n].push_back(i);
            }
        }
    }
    map<pair<size_t, size_t>, int> Pair2InterSize;
    void computeIntersectionSize()
    {
        for(auto iter = InvertedIndex.begin(); iter != InvertedIndex.end(); iter++)
        {
            const vector<size_t> &DocList = iter->second;
            if(DocList.size() == 1) continue;
            for(size_t i = 0; i < DocList.size(); i++)
            {
                for(size_t j = i + 1; j < DocList.size(); j++)
                {
                    Pair2InterSize[make_pair(DocList[i], DocList[j])]++;
                }
            }
        }
    }
    vector<string> ans;
    void adjustToSimilarities(const vector<vector<int>> &docs)
    {
        for(auto iter = Pair2InterSize.begin(); iter != Pair2InterSize.end(); iter++)
        {
            size_t IntersectionSize = iter->second;
            size_t UnionSize = docs[iter->first.first].size() + docs[iter->first.second].size() - IntersectionSize;
            ostringstream oss;
            oss << iter->first.first << ',' << iter->first.second << ": ";
            oss << fixed << setprecision(4) << static_cast<double>(IntersectionSize) / static_cast<double>(UnionSize) + 1e-9;
            ans.push_back(oss.str());
        }
    }
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        createInvertedIndex(docs);
        computeIntersectionSize();
        adjustToSimilarities(docs);
        return ans;
    }
};
