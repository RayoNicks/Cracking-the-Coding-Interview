class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        return moveDisk(A.size(), A, C, B);
    }
private:
    void moveDisk(size_t n, vector<int> &Origin, vector<int> &Destination, vector<int> &Buffer)
    {
        if(n == 1) return doMoveDisk(Origin, Destination);
        moveDisk(n - 1, Origin, Buffer, Destination);
        doMoveDisk(Origin, Destination);
        moveDisk(n - 1, Buffer, Destination, Origin);
    }
    void doMoveDisk(vector<int> &Origin, vector<int> &Destination)
    {
        int top = Origin.back();
        Origin.pop_back();
        Destination.push_back(top);
    }
};
