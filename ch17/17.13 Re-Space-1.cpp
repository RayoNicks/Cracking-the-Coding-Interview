class Solution {
private:
    unordered_set<string> dict;
    vector<int> Mem;
    int respace(const string &sentence, int idx)
    {
        if(idx == static_cast<int>(sentence.size())) return 0;
        if(Mem[idx] != INT_MAX) return Mem[idx];
        string part;
        int best = INT_MAX;
        for(int i = idx; i < static_cast<int>(sentence.size()); i++)
        {
            part.push_back(sentence[i]);
            int invalid = dict.find(part) != dict.end() ? 0 : part.size();
            if(invalid < best){
                int RestInvalid = respace(sentence, i + 1);
                if(invalid + RestInvalid < best){
                    best = invalid + RestInvalid;
                }
            }
        }
        Mem[idx] = best;
        return Mem[idx];
    }
public:
    int respace(vector<string> &dictionary, string sentence) {
        if(sentence.empty()) return 0;
        for(const string &word : dictionary)
        {
            dict.insert(word);
        }
        Mem.assign(sentence.size(), INT_MAX);
        respace(sentence, 0);
        return Mem[0];
    }
};
