class Solution {
public:
    int maximum(int a, int b) {
        int sa = sign(a), sb = sign(b);
        int sc = sign((long long)a - (long long)b);
        int x = (flip(sa) & flip(sb) & flip(sc)) | (flip(sa) & sb) | (sa & sb & flip(sc));
        int y = flip(x);
        return a * x + b * y;
    }
private:
    int sign(long long n)
    {
        return (n >> 63) & 0x1;
    }
    int flip(int s)
    {
        return 1 ^ s;
    }
};
