class Solution {
private:
    enum class Operator
    {
        ADD, SUBTRACT, MULTIPLY, DIVIDE
    };
    struct Term
    {
        Operator op;
        int num;
        Term() : op(Operator::ADD), num(0){}
        Term(Operator op, string Operand) : op(op), num(stoi(Operand)){}
    };
    vector<Term> Terms;
    void parseTerm(const string &Expression)
    {
        Operator op = Operator::ADD;
        string Operand;
        for(auto iter = Expression.begin(); iter != Expression.end(); iter++)
        {
            if(isspace(*iter));
            else if(isdigit(*iter)) Operand.push_back(*iter);
            else{
                Terms.push_back(Term(op, Operand));
                Operand.clear();
                switch(*iter)
                {
                case '+': op = Operator::ADD; break;
                case '-': op = Operator::SUBTRACT; break;
                case '*': op = Operator::MULTIPLY; break;
                case '/': op = Operator::DIVIDE; break;
                }
            }
        }
        Terms.push_back(Term(op, Operand));
    }
    Term apply(const Term &t1, const Term &t2)
    {
        Term result;
        switch(t2.op)
        {
        case Operator::ADD:
            result.num = t1.num + t2.num;
            break;
        case Operator::SUBTRACT:
            result.num = t1.num - t2.num;
            break;
        case Operator::MULTIPLY:
            result.num = t1.num * t2.num;
            break;
        case Operator::DIVIDE:
            result.num = t1.num / t2.num;
            break;
        }
        return result;
    }
    int compute()
    {
        Term result;
        Term processing;
        for(size_t i = 0; i < Terms.size(); i++)
        {
            const Term &current = Terms[i];
            const Term &next = i == Terms.size() - 1 ? Term() : Terms[i + 1];
            processing = apply(processing, current);
            if(next.op == Operator::ADD || next.op == Operator::SUBTRACT){
                result = apply(result, processing);
                processing = Term();
            }
        }
        return result.num;
    }
public:
    int calculate(string s) {
        parseTerm(s);
        return compute();
    }
};
