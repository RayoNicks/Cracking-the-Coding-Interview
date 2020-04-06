class Solution {
public:
    string replaceSpaces(string S, int length) {
        int cnt = 0, newPos;
        for(int i = 0; i < length; i++)
        {
            if(S[i] == ' ') cnt++;
        }
        newPos = length + (cnt << 1);
        S.resize(newPos);
        for(int i = length - 1; i >= 0; i--)
        {
            if(S[i] == ' '){
                S[newPos - 1] = '0';
                S[newPos - 2] = '2';
                S[newPos - 3] = '%';
                newPos -= 3;
            }
            else S[--newPos] = S[i];
        }
        return S;
    }
};
