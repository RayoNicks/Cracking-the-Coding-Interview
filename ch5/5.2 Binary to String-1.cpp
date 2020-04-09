class Solution {
private:
    const string strErr = "ERROR";
public:
    string printBin(double num) {
        if(num > 1.0 || num < 0.0){
            return strErr;
        }
        string strRet = "0.";
        while(num > 0.0){
            if(strRet.size() >= 34) return strErr;
            double r = num * 2;
            if(r >= 1.0){
                strRet.push_back('1');
                num = r - 1.0;
            }
            else{
                strRet.push_back('0');
                num = r;
            }
        }
        return strRet;
    }
};
