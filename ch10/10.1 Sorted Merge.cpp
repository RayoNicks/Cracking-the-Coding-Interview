class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int lastA = m - 1, lastB = n - 1, curr = m + n - 1;
        while(lastB >= 0){
            if(lastA >= 0 && A[lastA] > B[lastB]){
                A[curr] = A[lastA];
                lastA--;
            }
            else{
                A[curr] = B[lastB];
                lastB--;
            }
            curr--;
        }
    }
};
