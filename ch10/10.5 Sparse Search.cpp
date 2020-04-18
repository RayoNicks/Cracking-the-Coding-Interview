class Solution {
public:
    int findString(vector<string>& words, string s) {
        return findString(words, s, 0, words.size());
    }
private:
    int findString(const vector<string> &words, const string &s, int begin, int end)
    {
        if(begin >= end) return -1;
        int mid = begin + (end - begin) / 2;
        mid = shiftMid(words, mid, begin, end);
        if(mid == -1) return -1;
        if(words[mid] == s) return mid;
        if(s < words[mid]) return findString(words, s, begin, mid);
        else return findString(words, s, mid + 1, end);
    }
    int shiftMid(const vector<string> &words, int mid, int begin, int end)
    {
        int left = mid, right = mid;
        while(left >= begin && right < end){
            if(!words[left].empty()) return left;
            else if(!words[right].empty()) return right;
            left--, right++;
        }
        return -1;
    }
};
