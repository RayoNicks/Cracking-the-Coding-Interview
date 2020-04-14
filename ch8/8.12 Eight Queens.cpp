class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        Col.resize(n, -1);
        res.assign(n, string(n, '.'));
        placeQueen(n, 0);
        return allRes;
    }
private:
    vector<vector<string>> allRes;
    vector<string> res;
    vector<int> Col;
    void placeQueen(int n, int row)
    {
        if(row == n){
            allRes.push_back(res);
            return;
        }
        for(int col = 0; col < n; col++)
        {
            if(placeable(row, col)){
                Col[row] = col;
                res[row][col] = 'Q';
                placeQueen(n, row + 1);
                res[row][col] = '.';
                Col[row] = -1;
            }
        }
    }
    bool placeable(int row, int col)
    {
        for(int r = 0; r < row; r++)
        {
            if(Col[r] == col) return false;
            if(row - r == abs(col - Col[r])) return false;
        }
        return true;
    }
};
