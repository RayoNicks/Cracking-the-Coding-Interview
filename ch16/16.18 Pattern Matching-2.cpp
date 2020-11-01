class Solution {
public:
    bool patternMatching(string pattern, string value) {
        char MainPat = pattern[0];
        char AltPat = pattern[0] == 'a' ? 'b' : 'a';
        size_t MainCnt = 0, AltCnt = 0;
        for(char c : pattern)
        {
            if(c == MainPat) MainCnt++;
            else AltCnt++;
        }
        size_t FirstAlt = pattern.find(AltPat);
        for(size_t MainSize = 0; MainSize <= value.size(); MainSize++)
        {
            if(value.size() < MainSize * MainCnt) continue;
            size_t RemLen = value.size() - MainSize * MainCnt;
            string MainStr(value.data(), MainSize);
            if(AltCnt == 0 || RemLen % AltCnt == 0){
                size_t AltSize = AltCnt == 0 ? 0 : RemLen / AltCnt;
                string AltStr = AltSize == 0 ? "" : value.substr(FirstAlt * MainSize, AltSize);
                if(AltCnt > 0 && MainStr == AltStr) continue;
                size_t ValueIdx = MainSize;
                for(size_t PatternIdx = 1; PatternIdx < pattern.size(); PatternIdx++)
                {
                    if(pattern[PatternIdx] == MainPat){
                        if(MainStr != value.substr(ValueIdx, MainSize)) break;
                        else ValueIdx += MainSize;
                    }
                    else{
                        if(AltStr != value.substr(ValueIdx, AltSize)) break;
                        else ValueIdx += AltSize;
                    }
                }
                if(ValueIdx == value.size()) return true;
            }
        }
        return false;
    }
};
