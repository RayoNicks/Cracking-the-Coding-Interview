class StackOfPlates {
private:
    list<stack<int>> StackSet;
    size_t size;
public:
    StackOfPlates(int cap) {
        size = cap;
    }
    
    void push(int val) {
        if(size == 0) return;
        if(StackSet.empty() || StackSet.back().size() == size){
            StackSet.push_back(stack<int>());
        }
        StackSet.back().push(val);
    }
    
    int pop() {
        return popAt(StackSet.size() - 1);
    }
    
    int popAt(size_t index) {
        int ret;
        if(StackSet.empty() || index >= StackSet.size()){
            ret = -1;
        }
        else{
            list<stack<int>>::iterator iter = StackSet.begin();
            while(index > 0){
                iter++;
                index--;
            }
            ret = iter->top();
            iter->pop();
            if(iter->empty()){
                StackSet.erase(iter);
            }
        }
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
