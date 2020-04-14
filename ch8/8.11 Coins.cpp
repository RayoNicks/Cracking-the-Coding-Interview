class Solution {
private:
    const vector<int> Money = { 25, 10, 5, 1 };
    const int MOD = 1000000007;
public:
    int waysToChange(int n) {
        vector<int> Way(n + 1, 0);
        Way[0] = 1;
        for(size_t m = 0; m < Money.size(); m++)
        {
            for(int i = Money[m]; i <= n; i++)
            {
                Way[i] += Way[i - Money[m]];
                Way[i] %= MOD;
            }
        }
        return Way.back();
    }
};
