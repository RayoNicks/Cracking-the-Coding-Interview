class Solution {
private:
    vector<string> Names;
    map<string, size_t> Name2Idx;
    vector<int> Freqs;
    vector<pair<size_t, size_t>> Synonyms;
    vector<size_t> Group;
    void addNameFreq(const string &name, const int freq)
    {
        Name2Idx[name] = Names.size();
        Names.push_back(name);
        Group.push_back(Group.size());
        Freqs.push_back(freq);
    }
    void transformInput(const vector<string> &names, const vector<string> &synonyms)
    {
        for(string str : names)
        {
            string::size_type pos = str.find('(');
            string name = str.substr(0, pos);
            int freq = stoi(str.substr(pos + 1, str.size() - 2 - pos));
            addNameFreq(name, freq);
        }
        for(string str : synonyms)
        {
            string::size_type pos = str.find(',');
            string name1 = str.substr(1, pos - 1);
            string name2 = str.substr(pos + 1, str.size() - 2 - pos);
            if(Name2Idx.find(name1) == Name2Idx.end()){
                addNameFreq(name1, 0);
            }
            if(Name2Idx.find(name2) == Name2Idx.end()){
                addNameFreq(name1, 0);
            }
            Synonyms.push_back(make_pair(Name2Idx[name1], Name2Idx[name2]));
        }
    }
    size_t findLeader(size_t i)
    {
        if(Group[i] == i) return i;
        else return findLeader(Group[i]);
    }
    void groupName()
    {
        for(auto p : Synonyms)
        {
            size_t Leader1Idx = findLeader(p.first);
            size_t Leader2Idx = findLeader(p.second);
            if(Names[Leader1Idx] < Names[Leader2Idx]) Group[Leader2Idx] = Leader1Idx;
            else Group[Leader1Idx] = Leader2Idx;
        }
    }
    vector<string> transformOutput()
    {
        vector<string> result;
        map<string, int> Popular;
        for(size_t i = 0; i < Names.size(); i++)
        {
            size_t LeaderIdx = findLeader(i);
            Popular[Names[LeaderIdx]] += Freqs[i];
        }
        for(auto iter = Popular.begin(); iter != Popular.end(); iter++)
        {
            result.push_back(iter->first);
            result.back().push_back('(');
            result.back().append(to_string(iter->second));
            result.back().push_back(')');
        }
        return result;
    }
public:
    vector<string> trulyMostPopular(vector<string> &names, vector<string> &synonyms) {
        transformInput(names, synonyms);
        groupName();
        return transformOutput();
    }
};
