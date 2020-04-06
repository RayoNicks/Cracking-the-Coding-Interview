class Solution {
public:
    bool canPermutePalindrome(string s) {
        long long ll[2] = { 0 };
        for(auto c : s)
        {
            ll[c >> 6] ^= ((long long)1) << (c & 0x3f);
        }
        //��������ֶ���Ϊ0����ֱ�ӷ���false
        //Ȼ�����ĳһ����1�ĸ���̫�࣬Ҳ����false
        return !(ll[0] && ll[1]) && !((ll[0] & (ll[0] - 1)) || (ll[1] & (ll[1] - 1)));
    }
};
