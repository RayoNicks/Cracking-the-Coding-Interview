class Solution {
    static bool equal(const double d1, const double d2)
    {
        return abs(d1 - d2) <= 1e-6;
    }
    struct Line
    {
        double slope, intercept;
        bool bVertical;
        Line(const vector<int> &p1, const vector<int> &p2)
        {
            if(Solution::equal((double)p1[0], (double)p2[0])){
                bVertical = true;
                slope = 0.0;
                intercept = p1[0];
            }
            else{
                bVertical = false;
                slope = 1.0 * (p1[1] - p2[1]) / (p1[0] - p2[0]);
                intercept = p1[1] - slope * p1[0];
            }
        }
    };
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        int maxCnt = 0;
        int l1 = 0, l2 = 1;
        for(size_t i = 0; i < points.size(); i++)
        {
            for(size_t j = i + 1; j < points.size(); j++)
            {
                int cnt = 2;
                Line line(points[i], points[j]);
                for(size_t k = j + 1; k < points.size(); k++)
                {
                    if(!line.bVertical){
                        if(Solution::equal(line.slope * points[k][0] + line.intercept, (double)points[k][1])){
                            cnt++;
                        }
                    }
                    else{
                        if(Solution::equal(line.intercept, (double)points[k][0])){
                            cnt++;
                        }
                    }
                }
                if(cnt > maxCnt){
                    maxCnt = cnt;
                    l1 = i, l2 = j;
                }
            }
        }
        return vector<int>{l1, l2};
    }
};
