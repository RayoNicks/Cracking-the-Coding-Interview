class Solution {
public:
    int numberOf2sInRange(int n) {
        int left = n, curr, right = 0, cnt = 0, base = 1;
        while(1){
            curr = left % 10;
            left /= 10;
            if(curr > 2){
                cnt += (left + 1) * base;
            }
            else if(curr < 2){
                cnt += left * base;
            }
            else{
                cnt += left * base + right + 1;
            }
            if(left == 0) break;
            right += curr * base;
            base *= 10;
        }
        return cnt;
    }
};
