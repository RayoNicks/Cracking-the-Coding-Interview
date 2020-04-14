class Solution {
public:
    vector<string> permutation(string S) {
        buildFreq(S);
        Permutation(S.size());
        return Perm;
    }
private:
    unordered_map<char, size_t> Freq;
    vector<string> Perm;
    string res;
    void buildFreq(const string &str)
    {
        for(char c : str)
            Freq[c]++;
    }
    void Permutation(const size_t size)
    {
        if(size == 0){
            Perm.push_back(res);
            return;
        }
        unordered_map<char, size_t>::iterator iter = Freq.begin();
        while(iter != Freq.end()){
            if(iter->second != 0){
                res.push_back(iter->first);
                iter->second--;
                Permutation(size - 1);
                iter->second++;
                res.pop_back();
            }
            iter++;
        }
    }
};
