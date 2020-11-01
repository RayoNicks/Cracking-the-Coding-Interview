class MedianFinder {
    priority_queue<int, vector<int>, less<int>> MaxHeap;
    priority_queue<int, vector<int>, greater<int>> MinHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        size_t size = MaxHeap.size() + MinHeap.size();
        if(size == 0){
            MinHeap.push(num);
        }
        else if(size % 2 == 1){
            int right = MinHeap.top();
            if(num > right){
                MinHeap.pop();
                MaxHeap.push(right);
                MinHeap.push(num);
            }
            else{
                MaxHeap.push(num);
            }
        }
        else{
            int left = MaxHeap.top(), right = MinHeap.top();
            if(num <= left){
                MaxHeap.pop();
                MaxHeap.push(num);
                MinHeap.push(left);
            }
            else if(num >= right){
                MinHeap.push(num);
            }
            else{
                MinHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        size_t size = MaxHeap.size() + MinHeap.size();
        if(size % 2 == 1) return static_cast<double>(MinHeap.top());
        else return (MaxHeap.top() + MinHeap.top()) / 2.0; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
