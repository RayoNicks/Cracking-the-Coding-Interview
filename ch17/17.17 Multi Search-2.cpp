class Solution {
private:
    struct TrieNode
    {
        array<shared_ptr<TrieNode>, 26> Children;
        char ch;
        bool isTerm;
        size_t idx;
        TrieNode(const char c) : ch(c), isTerm(false), idx(0){}
        void setTerm(size_t i)
        {
            isTerm = true;
            idx = i;
        };
    };
    struct Trie
    {
        shared_ptr<TrieNode> RootPointer;
        vector<vector<int>> StartPositions;
        Trie(){ RootPointer = make_shared<TrieNode>(TrieNode(0)); }
        void addSuffix(const string &Suffix, const size_t i)
        {
            shared_ptr<TrieNode> NodePointer = RootPointer;
            for(char c : Suffix)
            {
                int idx = c - 'a';
                if(NodePointer->Children[idx] == nullptr){
                    NodePointer->Children[idx] = make_shared<TrieNode>(TrieNode(c));
                }
                NodePointer = NodePointer->Children[idx];
            }
            NodePointer->setTerm(i);
        }
        void searchStr(const string &str, const size_t StartPos)
        {
            shared_ptr<TrieNode> NodePointer = RootPointer;
            for(char c : str)
            {
                int idx = c - 'a';
                if(NodePointer->Children[idx] != nullptr) NodePointer = NodePointer->Children[idx];
                else break;
                if(NodePointer->isTerm) StartPositions[NodePointer->idx].push_back(StartPos);
            }
        }
    };
    Trie root;
    void constructSmallsTrie(const vector<string> &smalls)
    {
        for(size_t i = 0; i < smalls.size(); i++)
        {
            root.addSuffix(smalls[i], i);
        }
        root.StartPositions.resize(smalls.size());
    }
    void searchBig(const string &big)
    {
        for(size_t i = 0; i < big.size(); i++)
        {
            root.searchStr(big.substr(i), i);
        }
    }
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        constructSmallsTrie(smalls);
        searchBig(big);
        return root.StartPositions;
    }
};
