class MinStack {
private:
    stack<int> Stack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        Stack.push(x);
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
    }
    
    void pop() {
        if(Stack.top() == minStack.top()){
            minStack.pop();
        }
        Stack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
