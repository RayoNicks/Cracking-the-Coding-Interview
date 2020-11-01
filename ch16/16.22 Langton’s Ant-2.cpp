class Solution {
private:
    map<pair<int, int>, char> Arrival;
    int r = 0, c = 0;
    int top = 0, left = 0, bottom = 0, right = 0;
    enum class Orientation
    {
        LEFT, UP, RIGHT, DOWN
    };
    Orientation moveAnt(Orientation orient)
    {
        auto iter = Arrival.find(make_pair(r, c));
        char OldColor = iter != Arrival.end() ? iter->second : '_';
        switch(orient)
        {
        case Orientation::LEFT:
            if(OldColor == '_'){
                Arrival[make_pair(r, c)] = 'X';
                r--;
                top = r < top ? r : top;
                return Orientation::UP;
            }
            else{
                Arrival[make_pair(r, c)] = '_';
                r++;
                bottom = r > bottom ? r : bottom;
                return Orientation::DOWN;
            }
        case Orientation::UP:
            if(OldColor == '_'){
                Arrival[make_pair(r, c)] = 'X';
                c++;
                right = c > right ? c : right;
                return Orientation::RIGHT;
            }
            else{
                Arrival[make_pair(r, c)] = '_';
                c--;
                left = c < left ? c : left;
                return Orientation::LEFT;
            }
        case Orientation::RIGHT:
            if(OldColor == '_'){
                Arrival[make_pair(r, c)] = 'X';
                r++;
                bottom = r > bottom ? r : bottom;
                return Orientation::DOWN;
            }
            else{
                Arrival[make_pair(r, c)] = '_';
                r--;
                top = r < top ? r : top;
                return Orientation::UP;
            }
        case Orientation::DOWN:
            if(OldColor == '_'){
                Arrival[make_pair(r, c)] = 'X';
                c--;
                left = c < left ? c : left;
                return Orientation::LEFT;
            }
            else{
                Arrival[make_pair(r, c)] = '_';
                c++;
                right = c > right ? c : right;
                return Orientation::RIGHT;
            }
        default:;
        }
        return orient;
    }
public:
    vector<string> printKMoves(int K) {
        Arrival.insert(make_pair(make_pair(0, 0), '_'));
        Orientation orient = Orientation::RIGHT;
        for(int i = 0; i < K; i++)
        {
            orient = moveAnt(orient);
        }
        if(orient == Orientation::LEFT) Arrival[make_pair(r, c)] = 'L';
        else if(orient == Orientation::UP) Arrival[make_pair(r, c)] = 'U';
        else if(orient == Orientation::RIGHT) Arrival[make_pair(r, c)] = 'R';
        else Arrival[make_pair(r, c)] = 'D';
        vector<string> ret;
        for(int i = top; i <= bottom; i++)
        {
            ret.push_back("");
            for(int j = left; j <= right; j++)
            {
                auto iter = Arrival.find(make_pair(i, j));
                if(iter == Arrival.end()) ret.back().push_back('_');
                else ret.back().push_back(iter->second);
            }
        }
        return ret;
    }
};
