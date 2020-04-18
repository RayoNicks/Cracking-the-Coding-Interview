class Solution {
public:
    int search(vector<int>& arr, int target) {
        return search(arr, target, 0, arr.size());
    }
private:
    int search(const vector<int> &arr, int target, int begin, int end)
    {
        int mid = begin + (end - begin) / 2, ret;
        if(begin == end) return -1;
        if(arr[begin] < arr[mid]){
            if(target >= arr[begin] && target <= arr[mid]){
                ret = search(arr, target, begin, mid);
                if(ret != -1) return ret;
                else if(arr[mid] == target) return mid;
                else return -1;
            }
            else return search(arr, target, mid + 1, end);
        }
        else{
            ret = search(arr, target, begin, mid);
            if(ret != -1) return ret;
            else if(arr[mid] == target) return mid;
            else return search(arr, target, mid + 1, end);
        }
    }
};
