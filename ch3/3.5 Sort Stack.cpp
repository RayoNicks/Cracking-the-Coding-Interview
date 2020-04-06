class SortedStack {
private:
    stack<int> s;
public:
    SortedStack() {

    }
    
    void push(int val) {
        stack<int> sTmp;
        while(!s.empty() && s.top() < val){
            sTmp.push(s.top());
            s.pop();
        }
        s.push(val);
        while(!sTmp.empty()){
            s.push(sTmp.top());
            sTmp.pop();
        }
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
        }
    }
    
    int peek() {
        if(s.empty()) return -1;
        else return s.top();
    }
    
    bool isEmpty() {
        return s.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
