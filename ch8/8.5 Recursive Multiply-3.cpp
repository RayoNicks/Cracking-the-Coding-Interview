class Solution {
public:
    int multiply(int A, int B) {
        int smaller = A <= B ? A : B;
        int bigger = A <= B ? B : A;
        return calProduct(smaller, bigger);
    }
private:
    int calProduct(const int smaller, const int bigger)
    {
        if(smaller == 1) return bigger;
        int half = smaller >> 1;
        int side = calProduct(half, bigger);
        if(smaller & 0x1 == 1)
            return (side << 1) + bigger;
        else
            return side << 1;
    }
};
