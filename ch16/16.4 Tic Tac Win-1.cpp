class Solution {
public:
    string tictactoe(vector<string>& board) {
        char first;
        size_t r, c;
        r = 0;
        for(r = 0; r < board.size(); r++)
        {
            first = board[r][0];
            if(first == ' ') continue;
            c = 1;
            while(c < board[r].size()){
                if(board[r][c] != first) break;
                c++;
            }
            if(c == board[r].size()) return string(1, first);
        }
        for(c = 0; c < board[0].size(); c++){
            first = board[0][c];
            if(first == ' ') continue;
            r = 1;
            while(r < board.size()){
                if(board[r][c] != first) break;
                r++;
            }
            if(r == board.size()) return string(1, first);;
        }
        r = 0, c = 0;
        first = board[r][c];
        if(first != ' '){
            while(r < board.size() && c < board[r].size()){
                if(board[r][c] != first) break;
                r++, c++;
            }
            if(r == board.size() && c == board[0].size()) return string(1, first);;
        }
        r = 0, c = board[0].size();
        first = board[r][c - 1];
        if(first != ' '){
            while(r < board.size() && c > 0){
                if(board[r][c - 1] != first) break;
                r++, c--;
            }
            if(r == board.size() && c == 0) return string(1, first);
        }
        r = 0;
        while(r < board.size()){
            c = 0;
            while(c < board[r].size()){
                if(board[r][c] == ' ') return "Pending";
                c++;
            }
            r++;
        }
        return "Draw";
    }
};
