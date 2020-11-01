class Solution {
private:
    struct Element
    {
        int ele;
        size_t DocID;
        Element(int n, size_t ID) : ele(n), DocID(ID){}
        bool operator<(const Element &rhs)
        {
            if(ele < rhs.ele) return true;
            else if(ele == rhs.ele) return DocID < rhs.DocID;
            else return false;
        }
    };
    vector<Element> Sorted;
    void sortDocs(const vector<vector<int>> &docs)
    {
        for(size_t i = 0; i < docs.size(); i++)
        {
            const vector<int> &doc = docs[i];
            for(int n : doc)
            {
                Sorted.push_back(Element(n, i));
            }
        }
        sort(Sorted.begin(), Sorted.end());
    }
    map<pair<size_t, size_t>, int> Pair2InterSize;
    void computeIntersectionSize()
    {
        for(size_t i = 0; i < Sorted.size(); i++)
        {
            size_t j = i + 1;
            while(j < Sorted.size() && Sorted[j].ele == Sorted[i].ele){
                Pair2InterSize[make_pair(Sorted[i].DocID, Sorted[j].DocID)]++;
                j++;
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
        sortDocs(docs);
        computeIntersectionSize();
        adjustToSimilarities(docs);
        return ans;
    }
};
