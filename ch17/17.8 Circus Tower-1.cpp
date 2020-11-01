class Solution {
private:
    struct Person
    {
        int height, weight;
        Person(const int h, const int w) : height(h), weight(w){}
        bool operator<(const Person &p2)
        {
            if(height < p2.height) return true;
            else if(height == p2.height) return weight > p2.weight;
            else return false;
        }
    };
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<Person> Persons;
        for(size_t i = 0; i < height.size(); i++)
        {
            Persons.push_back(Person(height[i], weight[i]));
        }
        sort(Persons.begin(), Persons.end());
        vector<Person> ShortestLightest;
        for(const Person &person : Persons)
        {
            auto iter = lower_bound(ShortestLightest.begin(), ShortestLightest.end(), person, [](const Person &p1, const Person &p2){ return p1.weight < p2.weight; });
            if(iter == ShortestLightest.end()){
                ShortestLightest.push_back(person);
            }
            else{
                if(person.weight < iter->weight){
                    *iter = person;
                }
            }
        }
        return ShortestLightest.size();
    }
};
