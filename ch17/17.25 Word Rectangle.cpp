class Solution {
private:
    struct TrieNode
    {
        char ch;
        array<shared_ptr<TrieNode>, 26> Children;
        TrieNode(char c = '\0') : ch(c){}
    };
    struct Trie
    {
        shared_ptr<TrieNode> RootPointer;
        Trie(){ RootPointer = make_shared<TrieNode>(); }
        void addString(const string &str)
        {
            shared_ptr<TrieNode> NodePointer = RootPointer;
            for(char c : str)
            {
                if(NodePointer->Children[c - 'a'] == nullptr){
                    NodePointer->Children[c - 'a'] = make_shared<TrieNode>(TrieNode(c));
                }
                NodePointer = NodePointer->Children[c - 'a'];
            }
        }
        bool contain(const vector<string> &rect, const size_t col)
        {
            shared_ptr<TrieNode> NodePointer = RootPointer;
            for(const string &word : rect)
            {
                char c = word[col];
                if(NodePointer->Children[c - 'a'] == nullptr) return false;
                else NodePointer = NodePointer->Children[c - 'a'];
            }
            return true;
        }
    };
    struct Group
    {
        unordered_set<string> WordSet;
        Trie root;
        bool empty(){ return WordSet.empty(); }
        void addWord(const string &word)
        {
            WordSet.insert(word);
            root.addString(word);
        }
        bool partialContain(const vector<string> &rect, const size_t col){ return root.contain(rect, col); }
    };
    vector<Group> Groups;
    vector<string> ans, rect;
    bool Found = false;
    void divideWordByLength(const vector<string> &words)
    {
        for(const string &word : words)
        {
            if(word.length() >= Groups.size()) Groups.resize(word.length() + 1);
            Groups[word.length()].addWord(word);
        }
    }
    void DFS(size_t length, size_t height)
    {
        if(rect.size() == height){
            Found = true;
            ans = rect;
            return;
        }
        const Group &group = Groups[length];
        for(const string &word : group.WordSet)
        {
            if(!Found){
                rect.push_back(word);
                if(check(rect, height)){
                    DFS(length, height);
                }
                rect.pop_back();
            }
        }
    }
    bool check(const vector<string> &rect, const size_t height)
    {
        Group &group = Groups[height];
        for(size_t col = 0; col < rect[0].size(); col++)
        {
            if(!group.partialContain(rect, col)) return false;
        }
        return true;
    }
public:
    vector<string> maxRectangle(vector<string>& words) {
        divideWordByLength(words);
        for(size_t length = Groups.size(); length > 1; length--)
        {
            for(size_t height = length; height > 1; height--)
            {
                if(!Groups[length - 1].empty() && !Groups[height - 1].empty()){
                    DFS(length - 1, height - 1);
                    if(!ans.empty()) return ans;
                }
            }
        }
        return ans;
    }
};
