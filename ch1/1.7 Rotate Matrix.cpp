class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int iTmp = 0;
        size_t N = matrix.size();
        //����N����ż������Ҫ��תN / 2�㣬�ӵ�0�㿪ʼ
        for(size_t layer = 0; layer < N / 2; layer++)
        {
            //ÿ����תN - 1 - layer��Ԫ�أ��ӵ�0����ʼ
            size_t first = layer, last = N - 1 - layer;
            for(size_t i = first; i < last; i++)
            {
                iTmp = matrix[layer][i];
                matrix[layer][i] = matrix[N - 1 - i][layer];//��->��
                matrix[N - 1 - i][layer] = matrix[N - 1 - layer][N - 1 - i];//��->��
                matrix[N - 1 - layer][N - 1 - i] = matrix[i][N - 1 - layer];//��->��
                matrix[i][N - 1 - layer] = iTmp;//��->��
            }
        }
    }
};
