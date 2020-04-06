class TripleInOne {
private:
    struct StackInfo
    {
        int base;
        int top;
    };
    int size;
    int* piTripleStack;
    StackInfo* pSI;
public:
    TripleInOne(int stackSize) : size(stackSize), piTripleStack(nullptr), pSI(nullptr)
    {
        piTripleStack = new int[3 * size];
        pSI = new StackInfo[3];
        for(int i = 0; i < 3; i++)
        {
            pSI[i].base = i * size;
            pSI[i].top = i * size;
        }
    }

    ~TripleInOne()
    {
        delete [] piTripleStack;
        delete [] pSI;
    }
    
    void push(int stackNum, int value) {
        if(pSI[stackNum].top - pSI[stackNum].base == size) return;
        else piTripleStack[pSI[stackNum].top++] = value;
    }
    
    int pop(int stackNum) {
        if(isEmpty(stackNum)) return -1;
        else return piTripleStack[--pSI[stackNum].top];
    }
    
    int peek(int stackNum) {
        if(isEmpty(stackNum)) return -1;
        else return piTripleStack[pSI[stackNum].top - 1];
    }
    
    bool isEmpty(int stackNum) {
        return pSI[stackNum].top == pSI[stackNum].base;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
