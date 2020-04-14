class Solution {
public:
    int multiply(int A, int B) {
        int smaller = A <= B ? A : B;
        int bigger = A <= B ? B : A;
        Memo.assign(smaller + 1, 0);
        Memo[1] = bigger;
        return calProduct(smaller, bigger);
    }
private:
    vector<int> Memo;
    int calProduct(const int smaller, const int bigger)
    {
        if(Memo[smaller] != 0) return Memo[smaller];
        int half = smaller >> 1;
        int side1 = calProduct(half, bigger);
        int side2 = side1;
        if(smaller & 0x1 == 1)
            side2 = calProduct(smaller - half, bigger);
        Memo[smaller] = side1 + side2;
        return Memo[smaller];
    }
};
