class Solution {
private:
    vector<int> vec;
    vector<int> res;
    void swap(int i, int j)
    {
        int t = vec[i];
        vec[i] = vec[j];
        vec[j] = t;
    }
    pair<int, int> partition(int left, int right, int pivot)
    {
        int curr = left, equal = left;
        while(curr < right){
            if(vec[curr] > pivot){
                swap(curr, right - 1);
                right--;
            }
            else if(vec[curr] < pivot){
                swap(curr, equal);
                equal++;
                curr++;
            }
            else{
                curr++;
            }
        }
        return make_pair(equal, curr);
    }
    void addResult(int left, int LeftEnd)
    {
        for(int i = left; i < LeftEnd; i++)
        {
            res.push_back(vec[i]);
        }
    }
    void rank(int left, int right, int k)
    {
        if(k == 0) return;
        int mid = (left + right) / 2;
        pair<int, int> p = partition(left, right, vec[mid]);
        int LeftSize = p.first - left, EqualSize = p.second - p.first;
        if(k < LeftSize){
            return rank(left, left + LeftSize, k);
        }
        else if(k <= LeftSize + EqualSize){
            return addResult(left, left + k);
        }
        else{
            addResult(left, left + LeftSize + EqualSize);
            return rank(left + LeftSize + EqualSize, right, k - LeftSize - EqualSize);
        }
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vec = arr;
        rank(0, vec.size(), k);
        // sort(res.begin(), res.end());
        return res;
    }
};
