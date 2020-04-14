class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        height = image.size();
        width = image[0].size();
        color = image[sr][sc];
        if(color != newColor) fillColor(image, sr, sc, newColor);
        return image;
    }
private:
    int color, width, height;
    void fillColor(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        image[sr][sc] = newColor;
        if(sr - 1 >= 0 && image[sr - 1][sc] == color){
            fillColor(image, sr - 1, sc, newColor);
        }
        if(sc - 1 >= 0 && image[sr][sc - 1] == color){
            fillColor(image, sr, sc - 1, newColor);
        }
        if(sr + 1 < height && image[sr + 1][sc] == color){
            fillColor(image, sr + 1, sc, newColor);
        }
        if(sc + 1 < width && image[sr][sc + 1] == color){
            fillColor(image, sr, sc + 1, newColor);
        }
    }
};
