class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> sizes;
        Visited.assign(land.size(), vector<bool>(land[0].size(), false));
        for(size_t r = 0; r < land.size(); r++)
        {
            for(size_t c = 0; c < land[r].size(); c++)
            {
                if(land[r][c] == 0 && !Visited[r][c]){
                    int size = ComputeSize(land, static_cast<int>(r), static_cast<int>(c));
                    sizes.push_back(size);
                }
            }
        }
        sort(sizes.begin(), sizes.end());
        return sizes;
    }
private:
    vector<vector<bool>> Visited;
    int ComputeSize(const vector<vector<int>> &land, const int r, const int c)
    {
        if(r < 0 || r >= land.size() || c < 0 || c >= land[r].size()) return 0;
        if(land[r][c] != 0 || Visited[r][c]) return 0;
        int size = 1;
        Visited[r][c] = true;
        for(int dr = -1; dr <= 1; dr++)
        {
            for(int dc = -1; dc <= 1; dc++)
            {
                size += ComputeSize(land, r + dr, c + dc);
            }
        }
        return size;
    }
};
