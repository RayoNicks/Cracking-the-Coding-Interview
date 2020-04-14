class Solution {
public:
    vector<string> generateParenthesis(int n) {
        genCombnation(n);
        return vector<string>(Comb.begin(), Comb.end());
    }
private:
    set<string> Comb;
    void genCombnation(int n)
    {
        if(n == 0){
            Comb.insert("");
            return;
        }
        genCombnation(n - 1);
        vector<string> subComb(Comb.begin(), Comb.end());
        Comb.clear();
        for(size_t i = 0; i < subComb.size(); i++)
        {
            const string &strComb = subComb[i];
            for(size_t pos = 0; pos < strComb.size(); pos++)
            {
                Comb.insert(strComb.substr(0, pos) + "()" + strComb.substr(pos));
            }
            Comb.insert(strComb + "()");
        }
    }
};
