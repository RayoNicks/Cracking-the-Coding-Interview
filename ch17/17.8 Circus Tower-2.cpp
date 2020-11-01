class Solution {
private:
    struct Person
    {
        int height, weight;
        Person(const int h, const int w) : height(h), weight(w){}
        bool operator<(const Person &p2)
        {
            if(height < p2.height) return true;
            else if(height == p2.height) return weight < p2.weight;
            else return false;
        }
    };
    void update(vector<Person> &ShortestLightest, vector<pair<Person, size_t>> &tmp)
    {
        for(auto p : tmp)
        {
            if(p.second >= ShortestLightest.size()){
                ShortestLightest.push_back(p.first);
            }
            else if(p.first.weight < ShortestLightest[p.second].weight){
                ShortestLightest[p.second] = p.first;
            }
        }
    }
public:
    int bestSeqAtIndex(const vector<int>& height, const vector<int>& weight) {
        vector<Person> Persons;
        for(size_t i = 0; i < height.size(); i++)
        {
            Persons.push_back(Person(height[i], weight[i]));
        }
        sort(Persons.begin(), Persons.end());
        int CurrHeight = Persons[0].height;
        vector<pair<Person, size_t>> tmp;
        vector<Person> ShortestLightest;
        for(size_t i = 0; i < Persons.size(); i++)
        {
            const Person &person = Persons[i];
            if(CurrHeight != person.height){
                update(ShortestLightest, tmp);
                tmp.clear();
                CurrHeight = person.height;
            }
            auto iter = lower_bound(ShortestLightest.begin(), ShortestLightest.end(), person, [](const Person &p1, const Person &p2){ return p1.weight < p2.weight; });
            if(iter == ShortestLightest.end()){
                tmp.push_back(make_pair(person, ShortestLightest.size()));
            }
            else{
                tmp.push_back(make_pair(person, iter - ShortestLightest.begin()));
            }
        }
        update(ShortestLightest, tmp);
        return ShortestLightest.size();
    }
};
