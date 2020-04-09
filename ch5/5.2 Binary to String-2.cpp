class Solution {
private:
    const string strErr = "ERROR";
public:
    string printBin(double num) {
        if(num > 1.0 || num < 0.0){
            return strErr;
        }
        double fraction = 0.5;
        string strRet = "0.";
        while(num > 0.0){
            if(strRet.size() >= 34) return strErr;
            if(num >= fraction){
                strRet.push_back('1');
                num -= fraction;
            }
            else{
                strRet.push_back('0');
            }
            fraction /= 2.0;
        }
        return strRet;
    }
};
