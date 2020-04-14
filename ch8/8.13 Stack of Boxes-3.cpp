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
        vector<int> Height(Boxes.size(), 0);
        Height[0] = Boxes[0].height;
        int max = Height[0];
        for(size_t i = 1; i < Boxes.size(); i++)
        {
            Height[i] = Boxes[i].height;
            for(size_t j = 0; j < i; j++)
            {
                if(Boxes[j].above(Boxes[i])){
                    if(Height[i] < Height[j] + Boxes[i].height){
                        Height[i] = Height[j] + Boxes[i].height;
                    }
                }
            }
            if(max < Height[i]) max = Height[i];
        }
        return max;
    }
private:
    vector<Box> Boxes;
    void convertBox(const vector<vector<int>> &box)
    {
        for(size_t i = 0; i < box.size(); i++)
        {
            Boxes.push_back(Box(box[i][0], box[i][1], box[i][2]));
        }
    }
};
