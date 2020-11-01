class Solution {
private:
    vector<int> Operands;
    vector<char> Operators;
    string Operand;
    void addOperand()
    {
        Operands.push_back(stoi(Operand));
        Operand.clear();   
    }
    int priority(char op)
    {
        if(op == '+' || op == '-') return 0;
        else return 1;
    }
    int apply(const int operand1, const int operand2, const char op)
    {
        if(op == '+') return operand1 + operand2;
        else if(op == '-') return operand1 - operand2;
        else if(op == '*') return operand1 * operand2;
        else return operand1 / operand2;
    }
    void compute()
    {
        int operand2 = Operands.back();
        Operands.pop_back();
        int operand1 = Operands.back();
        Operands.pop_back();
        Operands.push_back(apply(operand1, operand2, Operators.back()));
        Operators.pop_back();
    }
public:
    int calculate(string s) {
        for(char c : s)
        {
            if(isspace(c));
            else if(isdigit(c)) Operand.push_back(c);
            else{
                addOperand();
                while(!Operators.empty() && priority(Operators.back()) >= priority(c)){
                    compute();
                }
                Operators.push_back(c);
            }
        }
        addOperand();
        while(!Operators.empty()){
            compute();
        }
        return Operands[0];
    }
};
