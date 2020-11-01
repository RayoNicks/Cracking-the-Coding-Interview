class Solution {
private:
    vector<string> Grid;
    int r = 0, c = 0;
    int top = 0, left = 0, bottom = 0, right = 0;
    enum class Orientation
    {
        LEFT, UP, RIGHT, DOWN
    };
    char flip(){ return Grid[r][c] != 'X' ? 'X' : '_'; }
    Orientation moveAnt(Orientation orient)
    {
        char OldColor = Grid[r][c] != 'X' ? '_' : 'X';
        switch(orient)
        {
        case Orientation::LEFT:
            Grid[r][c] = flip();
            if(OldColor == '_'){
                r--;
                top = r < top ? r : top;
                return Orientation::UP;
            }
            else{
                r++;
                bottom = r > bottom ? r : bottom;
                return Orientation::DOWN;
            }
        case Orientation::UP:
            Grid[r][c] = flip();
            if(OldColor == '_'){
                c++;
                right = c > right ? c : right;
                return Orientation::RIGHT;
            }
            else{
                c--;
                left = c < left ? c : left;
                return Orientation::LEFT;
            }
        case Orientation::RIGHT:
            Grid[r][c] = flip();
            if(OldColor == '_'){
                r++;
                bottom = r > bottom ? r : bottom;
                return Orientation::DOWN;
            }
            else{
                r--;
                top = r < top ? r : top;
                return Orientation::UP;
            }
        case Orientation::DOWN:
            Grid[r][c] = flip();
            if(OldColor == '_'){
                c--;
                left = c < left ? c : left;
                return Orientation::LEFT;
            }
            else{
                c++;
                right = c > right ? c : right;
                return Orientation::RIGHT;
            }
        }
    }
    void adjustGrid()
    {
        if(r == static_cast<int>(Grid.size())){
            for(int i = 0; i < r; i++)
            {
                Grid.push_back(string(Grid[0].size(), ' '));
            }
        }
        else if(c == static_cast<int>(Grid[0].size())){
            for(auto &str : Grid)
            {
                str.append(str.size(), ' ');
            }
        }
        else if(r < 0){
            int OriginRow = static_cast<int>(Grid.size());
            r += OriginRow, top += OriginRow, bottom += OriginRow;
            for(int i = 0; i < OriginRow; i++)
            {
                Grid.push_back(Grid[i]);
                Grid[i].assign(Grid[i].size(), ' ');
            }
        }
        else if(c < 0){
            int OriginCol = static_cast<int>(Grid[0].size());
            c += OriginCol, left += OriginCol, right += OriginCol;
            for(auto &str : Grid)
            {
                str = string(str.size(), ' ') + str;
            }
        }
    }
public:
    vector<string> printKMoves(int K) {
        Grid.assign(1, string(1, ' '));
        Orientation orient = Orientation::RIGHT;
        for(int i = 0; i < K; i++)
        {
            orient = moveAnt(orient);
            adjustGrid();
        }
        if(orient == Orientation::LEFT) Grid[r][c] = 'L';
        else if(orient == Orientation::UP) Grid[r][c] = 'U';
        else if(orient == Orientation::RIGHT) Grid[r][c] = 'R';
        else Grid[r][c] = 'D';
        vector<string> ret;
        for(int i = top; i <= bottom; i++)
        {
            ret.push_back("");
            for(int j = left; j <= right; j++)
            {
                if(Grid[i][j] == ' ') ret.back().push_back('_');
                else ret.back().push_back(Grid[i][j]);
            }
        }
        return ret;
    }
};
