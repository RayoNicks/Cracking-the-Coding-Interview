class Solution {
private:
    vector<vector<int>> RightZero, DownZero;
    void precompute(const vector<vector<int>> &matrix)
    {
        RightZero.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        DownZero.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        RightZero.back().back() = DownZero.back().back() = matrix.back().back() == 0 ? 1 : 0;
        for(size_t c = matrix.back().size() - 1; c > 0; c--)
        {
            RightZero.back()[c - 1] = matrix.back()[c - 1] == 0 ? RightZero.back()[c] + 1 : 0;
            DownZero.back()[c - 1] = matrix.back()[c - 1] == 0 ? 1 : 0;
        }
        for(size_t r = matrix.size() - 1; r > 0; r--)
        {
            RightZero[r - 1].back() = matrix[r - 1].back() == 0 ? 1 : 0;
            DownZero[r - 1].back() = matrix[r - 1].back() == 0 ? DownZero[r].back() + 1 : 0;
        }
        for(size_t r = matrix.size() - 1; r > 0; r--)
        {
            for(size_t c = matrix.size() - 1; c > 0; c--)
            {
                RightZero[r - 1][c - 1] = matrix[r - 1][c - 1] == 0 ? RightZero[r - 1][c] + 1 : 0;
                DownZero[r - 1][c - 1] = matrix[r - 1][c - 1] == 0 ? DownZero[r][c - 1] + 1 : 0;
            }
        }
    }
    vector<int> compute(const vector<vector<int>>& matrix)
    {
        for(size_t size = matrix.size(); size > 0; size--)
        {
            for(size_t r = 0; r + size <= matrix.size(); r++)
            {
                for(size_t c = 0; c + size <= matrix.size(); c++)
                {
                    pair<int, int> TopLeft(RightZero[r][c], DownZero[r][c]);
                    pair<int, int> TopRight(RightZero[r][c + size - 1], DownZero[r][c + size - 1]);
                    pair<int, int> BottomLeft(RightZero[r + size - 1][c], DownZero[r + size - 1][c]);
                    if(TopLeft.first >= size &&
                        TopLeft.second >= size &&
                        TopRight.second >= size &&
                        BottomLeft.first >= size){
                            return { static_cast<int>(r), static_cast<int>(c), static_cast<int>(size) };
                        }
                }
            }
        }
        return {};
    }
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        precompute(matrix);
        return compute(matrix);
    }
};
