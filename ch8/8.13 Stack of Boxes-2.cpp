struct Box
{
    int width, depth, height;
public:
    Box(int w, int d, int h)
        : width(w), depth(d), height(h){}
    bool above(const Box &bottom)
    {
        return width < bottom.width && depth < bottom.depth && height < bottom.height; 
    }
};
bool operator<(const Box &b1, const Box &b2)
{
    return b1.width < b2.width;
}
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        convertBox(box);
        sort(Boxes.begin(), Boxes.end());
        MaxHeight.assign(Boxes.size(), 0);
        MaxHeight[0] = Boxes[0].height;
        return pileBox(Boxes.size() - 1, Box(INT_MAX, INT_MAX, INT_MAX));
    }
private:
    vector<Box> Boxes;
    vector<int> MaxHeight;
    int pileBox(const size_t curr, const Box &top)
    {
        Box &newTop = Boxes[curr];
        int withHeight = 0, withoutHeight = 0;
        if(newTop.above(top)){
            if(MaxHeight[curr] == 0){
                MaxHeight[curr] = pileBox(curr - 1, newTop);
                MaxHeight[curr] += newTop.height;
            }
            withHeight = MaxHeight[curr];
        }
        if(curr != 0) withoutHeight = pileBox(curr - 1, top);
        return withHeight > withoutHeight ? withHeight : withoutHeight;
    }
    void convertBox(const vector<vector<int>> &box)
    {
        for(size_t i = 0; i < box.size(); i++)
        {
            Boxes.push_back(Box(box[i][0], box[i][1], box[i][2]));
        }
    }
};
