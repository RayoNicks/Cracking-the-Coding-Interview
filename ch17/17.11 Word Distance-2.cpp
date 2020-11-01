class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        multimap<string, size_t> WordPositon;
        for(size_t i = 0; i < words.size(); i++)
        {
            WordPositon.insert(make_pair(words[i], i));
        }
        auto Word1LowerBound = WordPositon.lower_bound(word1);
        auto Word1UpperBound = WordPositon.upper_bound(word1);
        auto Word2LowerBound = WordPositon.lower_bound(word2);
        auto Word2UpperBound = WordPositon.upper_bound(word2);
        int MinDistance = words.size();
        for(multimap<string, size_t>::iterator iterWord1 = Word1LowerBound, iterWord2 = Word2LowerBound; iterWord1 != Word1UpperBound && iterWord2 != Word2UpperBound;)
        {
            int tmp = abs(int(iterWord1->second - iterWord2->second));
            if(tmp < MinDistance){
                MinDistance = tmp;
            }
            if(iterWord1->second < iterWord2->second){
                iterWord1++;
            }
            else{
                iterWord2++;
            }
        }
        return MinDistance;
    }
};
