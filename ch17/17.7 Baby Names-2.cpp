class Solution {
private:
    vector<string> Names;
    map<string, size_t> Name2Idx;
    vector<int> Freqs;
    vector<vector<bool>> Graph;
    map<string, int> Popular;
    void addNameFreq(const string &name, const int freq)
    {
        Name2Idx[name] = Names.size();
        Names.push_back(name);
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
        vector<pair<size_t, size_t>> Synonyms;
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
        Graph.assign(Names.size(), vector<bool>(Names.size(), false));
        for(auto p : Synonyms)
        {
            Graph[p.first][p.second] = Graph[p.second][p.first] = true;
        }
    }
    void groupName()
    {
        vector<bool> Visited(Names.size(), false);
        for(size_t i = 0; i < Names.size(); i++)
        {
            if(!Visited[i]){
                int TotalFreq = 0;
                string LessName(Names[i]);
                queue<size_t> group;
                group.push(i);
                Visited[i] = true;
                while(!group.empty()){
                    size_t FrontIdx = group.front();
                    group.pop();
                    if(Names[FrontIdx] < LessName) LessName = Names[FrontIdx];
                    TotalFreq += Freqs[FrontIdx];
                    for(size_t adj = 0; adj < Names.size(); adj++)
                    {
                        if(Graph[FrontIdx][adj] && !Visited[adj]){
                            group.push(adj);
                            Visited[adj] = true;
                        }
                    }
                }
                Popular[LessName] = TotalFreq;
            }
        }
    }
    vector<string> transformOutput()
    {
        vector<string> result;
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
