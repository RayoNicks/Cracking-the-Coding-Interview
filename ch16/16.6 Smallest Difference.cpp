class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        size_t idxA = 0, idxB = 0;
        unsigned long long ullMin = ULLONG_MAX;
        while(idxA < a.size() && idxB < b.size()){
            long long llDiff = a[idxA] - b[idxB];
            if(ullMin > abs(llDiff)) ullMin = abs(llDiff);
            if(a[idxA] <= b[idxB]) idxA++;
            else idxB++;
        }
        return ullMin;
    }
};
