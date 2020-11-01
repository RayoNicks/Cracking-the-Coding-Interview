class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<unsigned long long> vec(1, 1);
        set<unsigned long long> back;
        int three = 1, five, seven;
        for(int i = 0; i < k ;i++)
        {
            unsigned long long n = vec.back();
            back.insert(3 * n);
            back.insert(5 * n);
            back.insert(7 * n);
            vec.push_back(*back.begin());
            back.erase(back.begin());
        }
        return vec[k - 1];
    }
};
