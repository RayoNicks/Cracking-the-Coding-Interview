class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int> ans(2, 0);
        map<char, int> m;
        for(size_t s = 0; s < solution.size(); s++)
        {
            if(solution[s] == guess[s]) ans[0]++;
            else m[solution[s]]++;
        }
        for(size_t g = 0; g < guess.size(); g++)
        {
            if(guess[g] != solution[g]){
                auto iter = m.find(guess[g]);
                if(iter != m.end()){
                    ans[1]++;
                    iter->second--;
                    if(iter->second == 0) m.erase(iter);
                }
            }
        }
        return ans;
    }
};
