class Solution {
    const double EPS = 1e-6;
    struct Point
    {
        double x, y;
        Point(const vector<int> &square)
        {
            x = square[0] + square[2] / 2.0;
            y = square[1] + square[2] / 2.0;
        }
        Point(const double &x, const double &y) : x(x), y(y){}
    };
    bool equal(const double &d1, const double &d2)
    {
        return abs(d1 - d2) <= EPS;
    }
    Point extend(const Point &mid, const Point &other, const double &dir, const double &size)
    {
        double half = size / 2.0;
        if(equal(mid.x, other.x)){
            return Point(mid.x, mid.y + dir * half);
        }
        else{
            double slope = (other.y - mid.y) / (other.x - mid.x);
            if(abs(slope) < 1.0){
                return Point(mid.x + dir * half, mid.y + dir * half * slope);
            }
            else{
                return Point(mid.x + dir * half / slope, mid.y + dir * half);
            }
        }
    }
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        Point mid1(square1), mid2(square2);
        Point p11 = extend(mid1, mid2, -1.0, (double)square1[2]);
        Point p12 = extend(mid1, mid2, 1.0, (double)square1[2]);
        Point p21 = extend(mid2, mid1, -1.0, (double)square2[2]);
        Point p22 = extend(mid2, mid1, 1.0, (double)square2[2]);
        Point start = p11, end = p11;
        const vector<Point> vecPoints = {p12, p21, p22};
        for(size_t i = 0; i < vecPoints.size(); i++)
        {
            if(vecPoints[i].x < start.x || (equal(vecPoints[i].x, start.x) && vecPoints[i].y < start.y)){
                start = vecPoints[i];
            }
            else if(vecPoints[i].x > end.x || (equal(vecPoints[i].x, end.x) && vecPoints[i].y > end.y)){
                end = vecPoints[i];
            }
        }
        return {start.x, start.y, end.x, end.y};
    }
};
