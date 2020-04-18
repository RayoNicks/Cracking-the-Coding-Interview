class StreamRank {
private:
    vector<int> vec;
    size_t binarySearch(const int x)
    {
        size_t begin = 0, end = vec.size();
        while(begin < end){
            size_t mid = begin + (end - begin) / 2;
            if(vec[mid] <= x) begin = mid + 1;
            else end = mid;
        }
        return begin;
    }
public:
    StreamRank() {

    }
    
    void track(int x) {
        size_t pos = binarySearch(x);
        vec.push_back(0);
        for(size_t i = vec.size(); i > pos && i > 1; i--)
        {
            vec[i - 1] = vec[i - 2];
        }
        vec[pos] = x;
    }
    
    int getRankOfNumber(int x) {
        return binarySearch(x);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
