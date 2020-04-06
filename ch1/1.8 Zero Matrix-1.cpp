class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        vector<bool> vbRow(matrix.size(), false);
        vector<bool> vbCol(matrix[0].size(), false);
        for(size_t i = 0; i < matrix.size(); i++)
        {
            for(size_t j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0){
                    vbRow[i] = vbCol[j] = true;
                }
            }
        }
        for(size_t i = 0; i < vbRow.size(); i++)
        {
            if(vbRow[i]) matrix[i].assign(matrix[i].size(), 0);
        }
        for(size_t j = 0; j < vbCol.size(); j++)
        {
            if(vbCol[j]){
                for(size_t i = 0; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
