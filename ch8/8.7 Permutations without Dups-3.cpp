class Solution {
public:
    vector<string> permutation(string S) {
        Permutation(S, 0);
        return Perm;
    }
private:
    vector<string> Perm;
    void swapChar(char &c1, char &c2)
    {
        char c = c1;
        c1 = c2;
        c2 = c; 
    }
    void Permutation(string &str, const size_t curr)
    {
        if(curr == str.size()){
            Perm.push_back(str);
            return;
        }
        for(size_t idx = curr; idx < str.size(); idx++)
        {
            swapChar(str[curr], str[idx]);
            Permutation(str, curr + 1);
            swapChar(str[curr], str[idx]);
        }
    }
};
