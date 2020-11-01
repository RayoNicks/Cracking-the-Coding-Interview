class Solution {
private:
    enum class MemoryState
    {
        NOT, TRUE, FALSE
    };
    set<string> dict;
    vector<MemoryState> Mem;
    bool canBuild(const string &word)
    {
        if(Mem[word.size()] == MemoryState::TRUE) return true;
        else if(Mem[word.size()] == MemoryState::FALSE) return false;
        if(dict.find(word) != dict.end()) return true;
        for(size_t len = 1; len < word.size(); len++)
        {
            string left = word.substr(0, len);
            if(dict.find(left) != dict.end() && canBuild(word.substr(len))){
                Mem[word.size()] = MemoryState::TRUE;
                return true;
            }
        }
        Mem[word.size()] = MemoryState::FALSE;
        return false;
    }
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &w1, const string &w2)
        {
            if(w1.size() > w2.size()) return true;
            else if(w1.size() == w2.size()) return w1 < w2;
            else return false;
        });
        for(const string &w : words)
        {
            dict.insert(w);
        }
        for(const string &w : words)
        {
            dict.erase(w);
            Mem.assign(w.size() + 1, MemoryState::NOT);
            if(canBuild(w)) return w;
            dict.insert(w);
        }
        return "";
    }
};
