class Solution {
public:
    int waysToStep(int n) {
        Ways.assign(n + 1, 0);
        Ways[0] = 1;
        return countWay(n);
    }
private:
    const int MOD = 1000000007;
    vector<int> Ways;
    int countWay(int n)
    {
        if(n < 0) return 0;
        else if(Ways[n] != 0) return Ways[n];
        else{
            Ways[n] = (countWay(n - 1) + countWay(n - 2)) % MOD;
            Ways[n] += countWay(n - 3);
            Ways[n] %= MOD;
            return Ways[n];
        }
    }
};
