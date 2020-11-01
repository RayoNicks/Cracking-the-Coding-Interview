class Solution {
private:
    struct TrieNode
    {
        array<shared_ptr<TrieNode>, 26> Children;
        vector<size_t> Positions;
        char ch;
        TrieNode(const char c) : ch(c){}
        TrieNode(const char c, const size_t p) : ch(c){ addPosition(p); }
        void addPosition(const size_t pos){ Positions.push_back(pos); }
    };
    struct Trie
    {
        shared_ptr<TrieNode> RootPointer;
        Trie(){ RootPointer = make_shared<TrieNode>(TrieNode(0)); }
        void addSuffix(const string &Suffix, size_t StartPos)
        {
            shared_ptr<TrieNode> NodePointer = RootPointer;
            for(char c : Suffix)
            {
                int idx = c - 'a';
                if(NodePointer->Children[idx] == nullptr){
                    NodePointer->Children[idx] = make_shared<TrieNode>(TrieNode(c, StartPos));
                }
                else{
                    NodePointer->Children[idx]->addPosition(StartPos);
                }
                NodePointer = NodePointer->Children[idx];
                StartPos++;
            }
        }
        vector<int> searchStr(const string &str)
        {
            shared_ptr<TrieNode> NodePointer = RootPointer;
            for(char c : str)
            {
                int idx = c - 'a';
                if(NodePointer->Children[idx] != nullptr) NodePointer = NodePointer->Children[idx];
                else return {};
            }
            vector<int> StartPositions(NodePointer->Positions.size());
            transform(NodePointer->Positions.begin(), NodePointer->Positions.end(), StartPositions.begin(), [&str](const size_t EndPos)->int{ return static_cast<int>(EndPos + 1 - str.size()); });
            return StartPositions;
        }
    };
    Trie root;
    void constructBigTrie(const string &big)
    {
        for(size_t i = 0; i < big.size(); i++)
        {
            root.addSuffix(big.substr(i), i);
        }
    }
    vector<vector<int>> searchSmalls(const vector<string> &smalls)
    {
        vector<vector<int>> ret;
        for(const string &str : smalls)
        {
            vector<int> StartPositions = root.searchStr(str);
            ret.push_back(StartPositions);
        }
        return ret;
    }
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        constructBigTrie(big);
        return searchSmalls(smalls);
    }
};
