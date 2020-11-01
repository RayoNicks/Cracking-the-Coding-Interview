class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        vector<int> ans;
        int max = INT_MIN;
        for(int startRow = 0; startRow < matrix.size(); startRow++)
        {
            vector<int> partialSum(matrix[0].size(), 0);
            for(int endRow = startRow; endRow < matrix.size(); endRow++)
            {
                int sum = 0, startCol = 0;
                for(int endCol = 0; endCol < matrix[0].size(); endCol++)
                {
                    partialSum[endCol] += matrix[endRow][endCol];
                    sum += partialSum[endCol];
                    if(max < sum){
                        max = sum;
                        ans = { startRow, startCol, endRow, endCol };
                    }
                    if(sum < 0){
                        sum = 0;
                        startCol = endCol + 1;
                    }
                }
            }
        }
        return ans;
    }
};
