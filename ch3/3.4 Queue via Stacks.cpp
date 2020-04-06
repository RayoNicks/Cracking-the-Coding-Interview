class MyQueue {
private:
    stack<int> sOldest, sNewest;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sNewest.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp;
        if(sOldest.empty()){
            while(!sNewest.empty()){
                tmp = sNewest.top();
                sNewest.pop();
                sOldest.push(tmp);
            }
        }
        tmp = sOldest.top();
        sOldest.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        int ret = pop();
        sOldest.push(ret);
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sOldest.empty() && sNewest.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
