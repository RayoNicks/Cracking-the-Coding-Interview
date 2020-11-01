class Solution {
private:
    struct BFSNode
    {
        size_t curr, prev;
        bool Forward;
        BFSNode(size_t c = UINT_MAX, size_t p = UINT_MAX, bool b = false) : curr(c), prev(p), Forward(b){}
    };
    map<string, size_t> Word2Idx;
    vector<string> Idx2Word;
    vector<vector<bool>> Graph;
    vector<BFSNode> Visited;
    deque<string> Solution;
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
        Visited.assign(Idx2Word.size(), BFSNode());
    }
    BFSNode BFS(deque<BFSNode> &FromSource, const deque<BFSNode> &FromDest, bool Forward)
    {
        BFSNode node = FromSource.front();
        FromSource.pop_front();
        const vector<bool> &Adjacent = Graph[node.curr];
        for(size_t adj = 0; adj < Adjacent.size(); adj++)
        {
            if(Adjacent[adj]){
                if(Visited[adj].curr == UINT_MAX){
                    FromSource.push_back(BFSNode(adj, node.curr, Forward));
                    Visited[adj] = FromSource.back();
                }
                else if(Visited[adj].Forward != Forward) return BFSNode(adj, node.curr, Forward);
            }
        }
        return BFSNode();
    }
    void DoubleBFS(const size_t beginIdx, const size_t &endIdx)
    {
        deque<BFSNode> FromSource, FromDest;
        FromSource.push_back(BFSNode(beginIdx, UINT_MAX, true));
        Visited[beginIdx] = FromSource.front();
        FromDest.push_back(BFSNode(endIdx, UINT_MAX, false));
        Visited[endIdx] = FromDest.front();
        while(!FromSource.empty() || !FromDest.empty()){
            BFSNode collision = BFS(FromSource, FromDest, true);
            if(collision.curr != UINT_MAX) return mergePath(collision);
            collision = BFS(FromDest, FromSource, false);
            if(collision.curr != UINT_MAX) return mergePath(collision);
        }
    }
    void mergePath(const BFSNode &collision)
    {
        Solution.push_back(Idx2Word[collision.curr]);
        size_t prev = collision.prev;
        while(prev != UINT_MAX){
            if(collision.Forward) Solution.push_front(Idx2Word[prev]);
            else Solution.push_back(Idx2Word[prev]);
            prev = Visited[prev].prev;
        }
        prev = Visited[collision.curr].prev;
        while(prev != UINT_MAX){
            if(collision.Forward) Solution.push_back(Idx2Word[prev]);
            else Solution.push_front(Idx2Word[prev]);
            prev = Visited[prev].prev;
        }
    }
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        preprocess(beginWord, wordList);
        createGraph();
        auto iterBeginWord = Word2Idx.find(beginWord);
        auto iterEndWord = Word2Idx.find(endWord);
        if(iterEndWord == Word2Idx.end()) return vector<string>();
        DoubleBFS(iterBeginWord->second, iterEndWord->second);
        return vector<string>(Solution.begin(), Solution.end());
    }
};
