class Solution {
private:
    map<string, size_t> Word2Idx;
    vector<string> Idx2Word;
    vector<vector<bool>> Graph;
    vector<bool> Visited;
    vector<string> Path, Solution;
    bool Found = false;
    void preprocess(const string &beginWord, const vector<string> &wordList)
    {
        bool IsBeginInDict = false;
        for(const string &word : wordList)
        {
            if(beginWord == word) IsBeginInDict = true;
            Idx2Word.push_back(word);
        }
        if(!IsBeginInDict) Idx2Word.push_back(beginWord);
    }
    void createGraph()
    {
        map<string, vector<size_t>> WildCard2Word;
        for(size_t i = 0; i < Idx2Word.size(); i++)
        {
            const string &word = Idx2Word[i];
            Word2Idx[word] = i;
            string WildCard(word);
            for(size_t j = 0; j < word.size(); j++)
            {
                char c = WildCard[j];
                WildCard[j] = ' ';
                WildCard2Word[WildCard].push_back(i);
                WildCard[j] = c;
            }
        }
        Graph.assign(Idx2Word.size(), vector<bool>(Idx2Word.size(), false));
        for(auto iter = WildCard2Word.begin(); iter != WildCard2Word.end(); iter++)
        {
            const vector<size_t> &Adjacent = iter->second;
            for(size_t i = 0; i < Adjacent.size(); i++)
            {
                for(size_t j = i + 1; j < Adjacent.size(); j++)
                {
                    Graph[Adjacent[i]][Adjacent[j]] = Graph[Adjacent[j]][Adjacent[i]] = true;
                }
            }
        }
        Visited.assign(Idx2Word.size(), false);
    }
    void DFS(const size_t beginIdx, const size_t &endIdx)
    {
        if(beginIdx == endIdx){
            Found = true;
            Solution.assign(Path.begin(), Path.end());
            return;
        }
        for(size_t adj = 0; adj < Graph[beginIdx].size(); adj++)
        {
            if(!Found && Graph[beginIdx][adj] && !Visited[adj]){
                Visited[adj] = true;
                Path.push_back(Idx2Word[adj]);
                DFS(adj, endIdx);
                Path.pop_back();
            }
        }
    }
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        preprocess(beginWord, wordList);
        createGraph();
        auto iterBeginWord = Word2Idx.find(beginWord);
        auto iterEndWord = Word2Idx.find(endWord);
        if(iterEndWord == Word2Idx.end()) return Solution;
        Path.push_back(beginWord);
        Visited[iterBeginWord->second] = true;
        DFS(iterBeginWord->second, iterEndWord->second);
        return Solution;
    }
};
