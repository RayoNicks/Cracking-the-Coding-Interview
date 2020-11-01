class Solution {
public:
    int calculate(string s) {
        for(size_t i = s.size(); i > 0; i--)
        {
            if(s[i] == '+' || s[i] == '-'){
                int left = calculate(s.substr(0, i));
                int right = calculate(s.substr(i + 1));
                if(s[i] == '+') return left + right;
                else return left - right;
            }
        }
        for(size_t i = s.size(); i > 0; i--)
        {
            if(s[i] == '*' || s[i] == '/'){
                int left = calculate(s.substr(0, i));
                int right = calculate(s.substr(i + 1));
                if(s[i] == '*') return left * right;
                else return left / right;
            }
        }
        return stoi(s);
    }
};
