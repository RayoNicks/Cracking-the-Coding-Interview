class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first.size() == second.size()){
            return oneEditReplace(first, second);
        }
        else if(first.size() + 1 == second.length()){
            return oneEditInsert(first, second);
        }
        else if(second.size() + 1 == first.length()){
            return oneEditInsert(second, first);
        }
        else return false;
    }
private:
    bool oneEditReplace(const string &s1, const string &s2)
    {
        bool bDiff = false;
        for(size_t i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i]){
                if(bDiff) return false;
                else bDiff = true;
            }
        }
        return true;
    }
    bool oneEditInsert(const string &shorter, const string longer)
    {
        bool bInsert = false;
        for(size_t i = 0, j = 0; i < shorter.size() && j < longer.size(); i++, j++)
        {
            if(shorter[i] != longer[j]){
                if(bInsert) return false;
                else{
                    bInsert = true;
                    i--;
                }
            }
        }
        return true;
    }
};
