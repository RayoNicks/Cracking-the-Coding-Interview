class Solution {
private:
    vector<set<int>> Graph;
    void buildGraph(const int n, const vector<vector<int>> &graph)
    {
        int from, to;
        Graph.resize(n);
        for(size_t i = 0; i < graph.size(); i++)
        {
            from = graph[i][0], to = graph[i][1];
            Graph[from].insert(to);
        }
    }
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(start == target) return true;
        buildGraph(n, graph);
        deque<int> dq;
        vector<bool> Visit(n, false);
        dq.push_back(start);
        Visit[start] = true;
        int curr;
        while(!dq.empty()){
            curr = dq.front();
            dq.pop_front();
            const set<int> &Adjs = Graph[curr];
            auto iter = Adjs.begin();
            while(iter != Adjs.end()){
                if(!Visit[*iter]){
                    dq.push_back(*iter);
                    Visit[*iter] = true;
                }
                iter++;
            }
        }
        return Visit[target];
    }
};
