class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int Word1LastLocation = find(words.begin(), words.end(), word1) - words.begin();
        int Word2LastLocation = find(words.begin(), words.end(), word2) - words.begin();
        int MinDistance = INT_MAX;
        int begin = Word1LastLocation < Word2LastLocation ? Word1LastLocation : Word2LastLocation;
        for(int i = begin; i < static_cast<int>(words.size()); i++)
        {
            if(words[i] == word1){
                Word1LastLocation = i;
            }
            else if(words[i] == word2){
                Word2LastLocation = i;
            }
            else;
            size_t tmp = abs(Word1LastLocation - Word2LastLocation);
            if(tmp < MinDistance){
                MinDistance = tmp;
            }
        }
        return MinDistance;
    }
};
