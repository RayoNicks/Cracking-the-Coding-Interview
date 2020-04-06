class Solution {
public:
    bool oneEditAway(string first, string second) {
        const string &shorter = first.size() <= second.size() ? first : second;
        const string &longer = first.size() <= second.size() ? second : first;
        if(longer.size() - shorter.size() > 1) return false;
        bool bDiff = false;
        for(size_t i = 0, j = 0; i < shorter.size() && j < longer.size(); i++, j++)
        {
            if(shorter[i] != longer[j]){
                if(bDiff) return false;
                else{
                    bDiff = true;
                    if(longer.size() != shorter.size()){
                        i--;
                    }
                }
            }
        }
        return true;
    }
};
