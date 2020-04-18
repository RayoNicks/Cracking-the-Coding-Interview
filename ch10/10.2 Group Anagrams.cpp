class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mapAnagrams;
        for(size_t i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mapAnagrams[s].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        map<string, vector<string>>::iterator iter;
        for(iter = mapAnagrams.begin(); iter != mapAnagrams.end(); iter++)
        {
            ret.push_back(iter->second);
        }
        return ret;
    }
};
