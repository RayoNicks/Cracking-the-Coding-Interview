class Solution {
public:
    string tictactoe(vector<string>& board) {
        vector<Iterator> vecIter;
        for(size_t i = 0; i < board.size(); i++)
        {
            vecIter.push_back(Iterator(i, 0, 0, 1, board.size(), board[0].size()));
        }
        for(size_t j = 0; j < board[0].size(); j++)
        {
            vecIter.push_back(Iterator(0, j, 1, 0, board.size(), board[0].size()));
        }
        vecIter.push_back(Iterator(0, 0, 1, 1, board.size(), board[0].size()));
        vecIter.push_back(Iterator(0, board.size() - 1, 1, -1, board.size(), board[0].size()));
        for(Iterator iter : vecIter)
        {
            char first = board[iter.row][iter.col];
            if(first == ' ') continue;
            iter.next();
            while(!iter.end()){
                if(board[iter.row][iter.col] != first) break;
                iter.next();
            }
            if(iter.end()) return string(1, first);
        }
        for(size_t i = 0; i < board.size(); i++)
        {
            for(size_t j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == ' ') return "Pending";
            }
        }
        return "Draw";
    }
private:
    struct Iterator
    {
        int row, col;
        int rowInc, colInc;
        int rowBound, colBound;
        Iterator(int row, int col, int rowInc, int colInc, int rowBound, int colBound) : row(row), col(col), rowInc(rowInc), colInc(colInc), rowBound(rowBound), colBound(colBound){}
        void next()
        {
            row += rowInc;
            col += colInc;
        }
        bool end()
        {
            return !(0 <= row && row < rowBound && 0 <= col && col < colBound);
        }
    };
};
