class Solution {
public:
    vector<string> generateParenthesis(int n) {
        genCombination(n, n);
        return Comb;
    }
private:
    vector<string> Comb;
    string res;
    void genCombination(int leftRem, int rightRem)
    {
        if(leftRem == 0 && rightRem == 0){
            Comb.push_back(res);
            return;
        }
        if(leftRem > 0){
            res.push_back('(');
            genCombination(leftRem - 1, rightRem);
            res.pop_back();
        }
        if(rightRem > leftRem){
            res.push_back(')');
            genCombination(leftRem, rightRem - 1);
            res.pop_back();
        }
    }
};
