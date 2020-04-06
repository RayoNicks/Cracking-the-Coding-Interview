class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int iTmp = 0;
        size_t N = matrix.size();
        //无论N的奇偶，都需要旋转N / 2层，从第0层开始
        for(size_t layer = 0; layer < N / 2; layer++)
        {
            //每层旋转N - 1 - layer个元素，从第0个开始
            size_t first = layer, last = N - 1 - layer;
            for(size_t i = first; i < last; i++)
            {
                iTmp = matrix[layer][i];
                matrix[layer][i] = matrix[N - 1 - i][layer];//左->上
                matrix[N - 1 - i][layer] = matrix[N - 1 - layer][N - 1 - i];//下->左
                matrix[N - 1 - layer][N - 1 - i] = matrix[i][N - 1 - layer];//右->下
                matrix[i][N - 1 - layer] = iTmp;//上->右
            }
        }
    }
};
