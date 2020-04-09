class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        int next = NextCloset(num);
        int prev = PrevCloset(num);
        return { next, prev };
    }
private:
    int NextCloset(int num)
    {
        int n = num;
        int c0 = 0, c1 = 0;
        while((n & 0x1) == 0){
            c0++;
            n >>= 1;
        }
        while((n & 0x1) == 1){
            c1++;
            n >>= 1;
        }
        if(c1 + c0 == 31) return -1;
        int mask = 1 << (c0 + c1);
        num |= mask;
        num &= ~(mask - 1);
        num |= (1 << (c1 - 1)) - 1;
        return num;
    }
    int PrevCloset(int num)
    {
        int n = num;
        int c0 = 0, c1 = 0;
        while((n & 0x1) == 1){
            c1++;
            n >>= 1;
        }
        if(n == 0) return -1;
        while((n & 0x1) == 0){
            c0++;
            n >>= 1;
        }
        int mask = 1 << (c0 + c1 + 1);
        num &= ~(mask - 1);
        mask = ((1 << (c1 + 1)) - 1) << (c0 - 1);
        num |= mask;
        return num;
    }
};
