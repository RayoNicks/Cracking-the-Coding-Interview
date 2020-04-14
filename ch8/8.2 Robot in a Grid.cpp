class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        Visited.assign(obstacleGrid.size(), vector<bool>(obstacleGrid[0].size(), false));
        calculatePath(obstacleGrid, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);
        return Path;
    }
private:
    vector<vector<int>> Path;
    vector<vector<bool>> Visited;
    bool calculatePath(const vector<vector<int>> &obstacleGrid, const int r, const int c)
    {
        if(r < 0 || c < 0 || obstacleGrid[r][c] == 1) return false;
        if(Visited[r][c]) return false;
        else Visited[r][c] = true;
        vector<int> curr = { r, c };
        bool bOrigin = r == 0 && c == 0;
        if(bOrigin || calculatePath(obstacleGrid, r - 1, c) || calculatePath(obstacleGrid, r, c - 1)){
            Path.push_back(curr);
            return true;
        }
        else{
            return false;
        }
    }
};
