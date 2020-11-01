class WordsFrequency {
private:
    unordered_map<string, size_t> hash;
public:
    WordsFrequency(vector<string>& book) {
        for(const string &word : book)
        {
            hash[word]++;
        }
    }
    
    int get(string word) {
        unordered_map<string, size_t>::const_iterator citer;
        citer = hash.find(word);
        if(citer == hash.end()) return 0;
        else return citer->second;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
