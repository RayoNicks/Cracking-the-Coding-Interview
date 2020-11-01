class Solution {
private:
    vector<char> KeyBoard = {
        '2', '2', '2', 
        '3', '3', '3',
        '4', '4', '4',
        '5', '5', '5',
        '6', '6', '6',
        '7', '7', '7', '7',
        '8', '8', '8',
        '9', '9', '9', '9'
    };
    map<string, vector<string>> Table;
    void buildTable(const vector<string> &words)
    {
        for(auto word : words)
        {
            string num;
            for(auto c : word)
            {
                num.push_back(KeyBoard[c - 'a']);
            }
            Table[num].push_back(word);
        }
    }
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        buildTable(words);
        auto iter = Table.find(num);
        if(iter != Table.end()) return iter->second;
        else return {};
    }
};
