struct Point
{
    double x, y;
    Point(double dx = 0.0, double dy = 0.0) : x(dx), y(dy){}
    Point(int ix, int iy)
    {
        x = (double)ix;
        y = (double)iy;
    }
    bool leftdown(const Point &p) const
    {
        if(x < p.x) return true;
        else if(x > p.x) return false;
        else return y < p.y;
    }
};
struct LineSegment
{
    Point el, er;
    double slope, intercept;
    LineSegment(const Point &p1, const Point &p2)
    {
        if(p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y)){
            el = p1, er = p2;
        }
        else{
            el = p2, er = p1;
        }
        slope = (er.y - el.y) / (er.x - el.x);
        intercept = er.y - slope * er.x;
    };
    bool vertical() const
    {
        return !finite(slope);
    }
    bool contain(const Point &p) const
    {
        double t = (p.x - el.x) / (er.x - el.x);
        if(!finite(t)) t = (p.y - el.y) / (er.y - el.y);
        return 0.0 <= t && t <= 1.0;
    }   
};
class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        Point s1(start1[0], start1[1]), e1(end1[0], end1[1]);
        Point s2(start2[0], start2[1]), e2(end2[0], end2[1]);
        LineSegment ls1(s1, e1), ls2(s2, e2);
        if(ls1.vertical() || ls2.vertical()){
            return procVertical(ls1, ls2);
        }
        else if(abs(ls1.slope - ls2.slope) <= EPS && abs(ls1.intercept - ls2.intercept) <= EPS){
            return procSame(ls1, ls2);
        }
        else{
            Point inter;
            inter.x = (ls2.intercept - ls1.intercept) / (ls1.slope - ls2.slope);
            inter.y = inter.x * ls1.slope + ls1.intercept;
            if(ls1.contain(inter) && ls2.contain(inter)){
                return vector<double>{ inter.x, inter.y };
            }
            else return vector<double>();
        }
    }
private:
    const double EPS = 1E-6;
    vector<double> procVertical(const LineSegment &ls1, const LineSegment &ls2)
    {
        Point inter;
        if(ls1.vertical() && ls2.vertical()){
            if(abs(ls1.el.x - ls2.el.x) <= EPS){
                return procSame(ls1, ls2);
            }
        }
        else if(ls1.vertical()){
            inter.x = ls1.el.x;
            inter.y = ls2.slope * inter.x + ls2.intercept;
            if(ls1.contain(inter)){
                return vector<double>{ inter.x, inter.y };
            }
        }
        else {
            inter.x = ls2.el.x;
            inter.y = ls1.slope * inter.x + ls1.intercept;
            if(ls2.contain(inter)){
                return vector<double>{ inter.x, inter.y };
            }
        }
        return vector<double>();
    }
    vector<double> procSame(const LineSegment &ls1, const LineSegment &ls2)
    {
        if(ls1.el.leftdown(ls2.el)){
            if(ls1.contain(ls2.el)){
                return vector<double>{ ls2.el.x, ls2.el.y };
            }
        }
        else{
            if(ls2.contain(ls1.el)){
                return vector<double>{ ls1.el.x, ls1.el.y };
            }
        }
        return vector<double>();
    }
};
