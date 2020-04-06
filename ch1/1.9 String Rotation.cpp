class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        string s1s1(s1 + s1);
        string::size_type pos = s1s1.find(s2);
        if(pos == string::npos) return false;
        else return true;
    }
};
