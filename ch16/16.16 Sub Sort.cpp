class Solution {
public:
    vector<int> subSort(vector<int>& vec) {
        if(vec.empty()) return {-1, -1};
        vector<int>::iterator b = vec.begin() + 1;
        vector<int>::reverse_iterator e = vec.rbegin() + 1;
        while(b != vec.end()){
            if(*b < *(b - 1)) break;
            else b++;
        }
        while(e != vec.rend()){
            if(*e > *(e - 1)) break;
            else e++;
        }
        if(b > e.base()) return {-1, -1};
        auto min = b;
        auto max = e;
        for(auto i = b; i != vec.end(); i++)
        {
            if(*i <= *min) min = i;
        }
        for(auto ri = e; ri != vec.rend(); ri++)
        {
            if(*ri >= *max) max = ri;
        }
        int left = -1, right = -1;
        for(auto i = vec.begin(); i != b; i++)
        {
            if(*i > *min){
                left = i - vec.begin();
                break;
            }
        }
        for(auto ri = vec.rbegin(); ri != e; ri++)
        {
            if(*ri < *max){
                right = ri.base() - vec.begin() - 1;
                break;
            }
        }
        return {left, right};
    }
};
