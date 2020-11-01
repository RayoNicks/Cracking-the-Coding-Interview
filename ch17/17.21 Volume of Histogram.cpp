class Solution {
public:
    int trap(vector<int>& height) {
        vector<size_t> LeftMax(height.size());
        vector<size_t> RightMax(height.size());
        size_t max = 0;
        for(size_t i = 0; i < height.size(); i++)
        {
            if(max < height[i]) max = height[i];
            LeftMax[i] = (max);
        }
        max = 0;
        for(size_t i = height.size(); i > 0; i--)
        {
            if(max < height[i - 1]) max = height[i - 1];
            RightMax[i - 1] = max;
        }
        int sum = 0;
        for(size_t i = 0; i < LeftMax.size(); i++)
        {
            sum += min(LeftMax[i], RightMax[i]) - height[i];
        }
        return sum;
    }
};
