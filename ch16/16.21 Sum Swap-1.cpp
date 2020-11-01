class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        if((sum1 + sum2) % 2 != 0) return {};
        int half = (sum1 + sum2) / 2;
        set<int> set2;
        for_each(array2.begin(), array2.end(), [&set2](const int i){ set2.insert(i); });
        for(size_t i = 0; i < array1.size(); i++)
        {
            int target = half - sum1 + array1[i];
            if(set2.find(target) != set2.end()){
                return { array1[i], target };
            }
        }
        return {};
    }
};
