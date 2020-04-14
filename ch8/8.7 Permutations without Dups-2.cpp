class Solution {
public:
    vector<string> permutation(string S) {
        Permutation(S);
        return Perm;
    }
private:
    vector<string> Perm;
    string res;
    void Permutation(const string &str)
    {
        if(str.empty()){
            Perm.push_back(res);
            return;
        }
        for(size_t i = 0; i < str.size(); i++)
        {
            res.push_back(str[i]);
            Permutation(str.substr(0, i) + str.substr(i + 1));
            res.pop_back();
        }
    }
};
