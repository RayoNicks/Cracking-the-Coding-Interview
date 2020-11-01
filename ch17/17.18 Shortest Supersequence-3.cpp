class Solution {
private:
    vector<list<int>> Queues;
    void buildQueue(const vector<int> &big, const vector<int> &small)
    {
        unordered_map<int, list<int>> Locations;
        for(int s : small)
        {
            Locations.insert(make_pair(s, list<int>()));
        }
        for(int i = 0; i < static_cast<int>(big.size()); i++)
        {
            auto iter = Locations.find(big[i]);
            if(iter != Locations.end()) iter->second.push_back(i);
        }
        for(auto iter = Locations.begin(); iter != Locations.end(); iter++)
        {
            Queues.push_back(iter->second);
        }
    }
    struct HeapNode
    {
        int index;
        size_t QueueNumber;
        HeapNode(const int idx, const size_t qn) : index(idx), QueueNumber(qn){}
        bool operator>(const HeapNode &hn) const
        {
            return index > hn.index;
        }
    };
    vector<int> findClosestRange()
    {
        priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> heap;
        HeapNode Max(INT_MIN, 0);
        for(size_t i = 0; i < Queues.size(); i++)
        {
            if(Queues[i].empty()) return {};
            HeapNode tmp(Queues[i].front(), i);
            heap.push(tmp);
            Queues[i].pop_front();
            if(tmp > Max) Max = tmp;
        }
        int left = heap.top().index, right = Max.index;
        while(1){
            HeapNode top = heap.top();
            heap.pop();
            size_t qn = top.QueueNumber;
            if(Queues[qn].empty()) break;
            HeapNode tmp(Queues[qn].front(), qn);
            heap.push(tmp);
            Queues[qn].pop_front();
            if(tmp > Max) Max = tmp;
            if(Max.index - heap.top().index < right - left){
                left = heap.top().index;
                right = Max.index;
            }
        }
        return { left, right };
    }
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        buildQueue(big, small);
        return findClosestRange();
    }
};
