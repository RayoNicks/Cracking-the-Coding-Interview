class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return vsSpec[0];
        if(num < 0){
            ret.append(strNeg);
            num = -num;
        }
        convertPerThousand(num, 0);
        ret.pop_back();
        return ret;
    }
    void convertPerThousand(int num, const int big)
    {
        if(num >= 1000){
            convertPerThousand(num / 1000, big + 1);
            num %= 1000;
        }
        if(num != 0){
            convertDigit(num);
            ret.append(vsThousands[big]);
        }
    }
    void convertDigit(int num)
    {
        if(num >= 100){
            convertHundred(num / 100);
            num %= 100;
        }
        if(num >= 20){
            convertTen(num / 10);
            num %= 10;
        }
        if(num != 0){
            ret.append(vsSpec[num]); 
        }
    }
    void convertHundred(int num)
    {
        ret.append(vsSpec[num]);
        ret.append(strHrd);
    }
    void convertTen(int num)
    {
        ret.append(vsTens[num]);
    }
private:
    string ret;
    const vector<string> vsSpec = { 
        "Zero", "One ", "Two ", "Three ", "Four ",
        "Five ", "Six ", "Seven ", "Eight ", "Nine ",
        "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
        "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "
    };
    const vector<string> vsTens = {
        "", "", "Twenty ", "Thirty ", "Forty ",
        "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "
    };
    const vector<string> vsThousands = {
        "", "Thousand ", "Million ", "Billion "
    };
    const string strHrd = "Hundred ";
    const string strNeg = "Negative ";
};
