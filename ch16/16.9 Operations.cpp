class Operations {
public:
    Operations() {

    }
    
    int minus(int a, int b) {
        return a + neg(b);
    }
    
    int multiply(int a, int b) {
        if(a == 0 || b == 0) return 0;
        llong absa = a > 0 ? a : neg(a), absb = b > 0 ? b : neg(b);
        llong delta = absa, p = 0;
        while(absb != 0){
            if(absb & 0x1) p += delta;
            absb >>= 1;
            delta += delta;
        }
        if((a > 0 && b > 0) || (a < 0 && b < 0)) return p;
        else return minus(0, p);
    }
    
    int divide(int a, int b) {
        llong absa = a > 0 ? a : neg(a), absb = b > 0 ? b : neg(b);
        llong q = 0, p = 0, delta, x;
        while(p <= absa){
            delta = absb;
            x = 1;
            while(p + delta <= absa){
                p += delta;
                q += x;
                delta += delta;
                x += x;
            }
            if(x == 1) break;
        }
        if((a > 0 && b > 0) || (a < 0 && b < 0)) return q;
        else return minus(0, q);
    }
private:
    typedef long long llong;
    llong neg(llong ll)
    {
        llong sign = ll > 0 ? -1 : 1;
        llong neg = 0, delta;
        while(ll != 0){
            delta = sign;
            while((ll > 0 && ll + delta >= 0) || (ll < 0 && ll + delta <= 0)){
                ll += delta;
                neg += delta;
                delta += delta;
            }
        }
        return neg;
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */
