class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        vector<int> ans;
        int max = INT_MIN;
        for(int startRow = 0; startRow < matrix.size(); startRow++)
        {
            for(int endRow = startRow; endRow < matrix.size(); endRow++)
            {
                vector<int> partialSum(matrix[0].size(), 0);
                for(int c = 0; c < matrix[0].size(); c++)
                {
                    for(int r = startRow; r <= endRow; r++)
                    {
                        partialSum[c] += matrix[r][c];
                    }
                }
                int sum = 0, startCol = 0;
                for(int endCol = 0; endCol < matrix[0].size(); endCol++)
                {
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
