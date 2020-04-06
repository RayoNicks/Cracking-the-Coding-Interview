class Solution {
public:
    bool isUnique(string astr) {
        if(astr.size() > 128) return false;
        bool bSet[128] = {false};
        for(size_t i = 0; i < astr.size(); i++)
        {
            if(bSet[astr[i]]) return false;
            else bSet[astr[i]] = true;
        }
        return true;
    }
};
