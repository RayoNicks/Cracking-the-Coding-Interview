class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        bool bRow0 = false, bCol0 = false;
        for(size_t i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0) bCol0 = true;
        }
        for(size_t j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[0][j] == 0) bRow0 = true;
        }
        for(size_t i = 1; i < matrix.size(); i++)
        {
            for(size_t j = 1; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0){
                    cout << 1 << endl;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(size_t i = 1; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0){
                setRowZero(matrix, i);
            }
        }
        for(size_t j = 1; j < matrix[0].size(); j++)
        {
            if(matrix[0][j] == 0){
                setColZero(matrix, j);
            }
        }
        if(bRow0){
            setRowZero(matrix, 0);
        }
        if(bCol0){
            setColZero(matrix, 0);
        }
    }
private:
    void setRowZero(vector<vector<int>> &matrix, size_t row)
    {
        matrix[row].assign(matrix[row].size(), 0);
    }
    void setColZero(vector<vector<int>> &matrix, size_t col)
    {
        for(size_t i = 0; i < matrix.size(); i++)
        {
            matrix[i][col] = 0;
        }
    }
};
