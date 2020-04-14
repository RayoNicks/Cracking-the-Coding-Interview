class Solution {
public:
    vector<string> permutation(string S) {
        Permutation(S, S.size());
        return Perm;
    }
private:
    vector<string> Perm;
    void Permutation(const string &str, size_t size)
    {
        if(size == 0){
            Perm.push_back("");
            return;
        }
        Permutation(str, size - 1);
        char c = str[size - 1];
        size_t cnt = Perm.size();
        for(size_t idx = 0; idx < cnt; idx++)
        {
            for(size_t pos = 0; pos < size - 1; pos++)
            {
                const string &s = Perm[idx];
                Perm.push_back(s.substr(0, pos) + c + s.substr(pos));
            }
            Perm[idx].push_back(c);
        }
    }
};
