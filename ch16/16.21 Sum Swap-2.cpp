class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        if((sum1 + sum2) % 2 != 0) return {};
        int half = (sum1 + sum2) / 2;
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        size_t i = 0, j = 0;
        while(i < array1.size() && j < array2.size()){
            int ChangedSum = sum1 - array1[i] + array2[j];
            if(ChangedSum == half){
                return { array1[i], array2[j] };
            }
            else if(ChangedSum > half){
                i++;
            }
            else{
                j++;
            }
        }
        return {};
    }
};
