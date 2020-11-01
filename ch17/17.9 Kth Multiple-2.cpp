class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<unsigned long long> vec(1, 1);
        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> back;
        int three = 1, five, seven;
        for(int i = 0; i < k ;i++)
        {
            unsigned long long n = vec.back(), top;
            back.push(3 * n);
            back.push(5 * n);
            back.push(7 * n);
            top = back.top();
            vec.push_back(top);
            while(back.top() == top){
                back.pop();
            }
        }
        return vec[k - 1];
    }
};
