class Solution {
public:
    int reverseBits(int num) {
        if(num == INT_MAX) return sizeof(decltype(num)) * 8;
        int curr = 0, prev = 0;
        int ret = 0;
        while(num != 0){
            if((num & 0x1) == 1) curr++;
            else{
                if(ret < curr + 1 + prev) ret = curr + 1 + prev;
                prev = curr;
                curr = 0;
            }
            num >>= 1;
        }
        if(ret < curr + 1 + prev) ret = curr + 1 + prev;
        return ret;
    }
};
