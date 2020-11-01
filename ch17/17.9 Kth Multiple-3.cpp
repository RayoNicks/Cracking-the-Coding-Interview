class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<unsigned long long> vec(1, 1);
        deque<unsigned long long> three, five, seven;
        three.push_back(3);
        five.push_back(5);
        seven.push_back(7);
        for(int i = 0; i < k; i++)
        {
            unsigned long long MinEle = min(min(three.front(), five.front()), seven.front());
            vec.push_back(MinEle);
            if(MinEle == three.front()){
                three.pop_front();
                three.push_back(MinEle * 3);
                five.push_back(MinEle * 5);
                seven.push_back(MinEle * 7);
            }
            else if(MinEle == five.front()){
                five.pop_front();
                five.push_back(MinEle * 5);
                seven.push_back(MinEle * 7);
            }
            else{
                seven.pop_front();
                seven.push_back(MinEle * 7);
            }
        }
        return vec[k - 1];
    }
};
