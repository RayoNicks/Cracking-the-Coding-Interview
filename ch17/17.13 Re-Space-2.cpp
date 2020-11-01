class Solution {
private:
    unordered_set<string> dict;
public:
    int respace(vector<string>& dictionary, string sentence) {
        if(sentence.empty()) return 0;
        for(const string &word : dictionary)
        {
            dict.insert(word);
        }
        vector<int> Invalid(1, 0);
        for(size_t i = 1; i <= sentence.size(); i++)
        {
            Invalid.push_back(Invalid.back() + 1);
            for(const string &word : dict)
            {
                size_t len = word.size();
                if(len <= i && word == sentence.substr(i - len, len)){
                    if(Invalid[i - len] < Invalid[i]){
                        Invalid[i] = Invalid[i - len];
                    }
                }
            }
        }
        return Invalid.back();
    }
};
