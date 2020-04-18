class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        size_t row = 0, col = matrix[0].size();
        while(row < matrix.size() && col > 0){
            if(target > matrix[row][col - 1]){
                row++;
            }
            else if(target < matrix[row][col - 1]){
                col--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
