class Solution {
public:
    bool canPermutePalindrome(string s) {
        long long ll[2] = { 0 };
        for(auto c : s)
        {
            ll[c >> 6] ^= ((long long)1) << (c & 0x3f);
        }
        //如果两部分都不为0，则直接返回false
        //然后如果某一部分1的个数太多，也返回false
        return !(ll[0] && ll[1]) && !((ll[0] & (ll[0] - 1)) || (ll[1] & (ll[1] - 1)));
    }
};
