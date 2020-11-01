class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& arr) {
        unordered_map<int, int> FirstIndex;
        FirstIndex[0] = -1;
        int delta = 0, begin = 0, end = 0;
        for(size_t i = 0; i < arr.size(); i++)
        {
            if(isalpha(arr[i].front())) delta++;
            else delta--;
            auto iter = FirstIndex.find(delta);
            if(iter == FirstIndex.end()){
                FirstIndex[delta] = i;
            }
            else{
                if(end - begin < i - iter->second){
                    end = i + 1;
                    begin = iter->second + 1;
                }
            }
        }
        return vector<string>(arr.begin() + begin, arr.begin() + end);
    }
};
