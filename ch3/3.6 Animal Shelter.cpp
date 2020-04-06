class AnimalShelf {
private:
    queue<pair<int, int>> qCat;
    queue<pair<int, int>> qDog;
    const int CatType = 0, DogType = 1;
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if(animal[1] == CatType){
            qCat.push(pair<int, int>(animal[0], CatType));
        }
        else if(animal[1] == DogType){
            qDog.push(pair<int, int>(animal[0], DogType));
        }
        else;
    }
    
    vector<int> dequeueAny() {
        vector<int> ret;
        if(qCat.empty() && qDog.empty()){
            return {-1, -1};
        }
        else if(qCat.empty()){
            return dequeueDog();
        }
        else if(qDog.empty()){
            return dequeueCat();
        }
        else{
            if(qCat.front().first < qDog.front().first){
                return dequeueCat();
            }
            else{
                return dequeueDog();
            }
        }
    }
    
    vector<int> dequeueDog() {
        vector<int> ret;
        if(qDog.empty()){
            return {-1, -1};
        }
        else{
            ret.push_back(qDog.front().first);
            ret.push_back(qDog.front().second);
            qDog.pop();
            return ret;
        }
    }
    
    vector<int> dequeueCat() {
        vector<int> ret;
        if(qCat.empty()){
            return {-1, -1};
        }
        else{
            ret.push_back(qCat.front().first);
            ret.push_back(qCat.front().second);
            qCat.pop();
            return ret;
        }
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
