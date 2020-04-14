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
        int maxHeight = 0, height;
        for(size_t btm = Boxes.size(); btm > 0; btm--)
        {
            height = pileBox(btm - 1);
            maxHeight = height > maxHeight ? height : maxHeight;
        }
        return maxHeight;
    }
private:
    vector<Box> Boxes;
    vector<int> MaxHeight;
    int pileBox(const size_t btmIdx)
    {
        if(MaxHeight[btmIdx] != 0) return MaxHeight[btmIdx];
        int maxHeight = 0, height;
        for(size_t btm = btmIdx; btm > 0; btm--)
        {
            if(Boxes[btm - 1].above(Boxes[btmIdx])){
                height = pileBox(btm - 1);
                maxHeight = height > maxHeight ? height : maxHeight;
            }
        }
        maxHeight += Boxes[btmIdx].height;
        MaxHeight[btmIdx] = maxHeight;
        return maxHeight;
    }
    void convertBox(const vector<vector<int>> &box)
    {
        for(size_t i = 0; i < box.size(); i++)
        {
            Boxes.push_back(Box(box[i][0], box[i][1], box[i][2]));
        }
    }
};
