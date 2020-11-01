class Solution {
private:
    set<int> sTotal;
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        for(int s = 0; s <= k; s++)
        {
            sTotal.insert(shorter * s + longer * (k - s));
        }
        sTotal.erase(0);
        return vector<int>(sTotal.begin(), sTotal.end());
    }
};
