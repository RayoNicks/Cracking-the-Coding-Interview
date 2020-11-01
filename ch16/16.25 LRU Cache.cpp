class LRUCache {
private:
    struct CacheLine
    {
        int key, value;
        shared_ptr<CacheLine> prev, next;
        CacheLine(int k, int v) : key(k), value(v){}
    };
    size_t MaxCapacity;
    unordered_map<int, shared_ptr<CacheLine>> Cache;
    shared_ptr<CacheLine> Head, Tail;
public:
    LRUCache(int capacity) {
        MaxCapacity = static_cast<size_t>(capacity);
        Head = make_shared<CacheLine>(CacheLine(0, 0));
        Tail = make_shared<CacheLine>(CacheLine(0, 0));
        Head->next = Tail;
        Tail->prev = Head;
    }
    
    int get(int key) {
        auto iter = Cache.find(key);
        if(iter != Cache.end()){
            shared_ptr<CacheLine> cl = iter->second;
            cl->prev->next = cl->next;
            cl->next->prev = cl->prev;
            cl->prev = Head;
            cl->next = Head->next;
            Head->next->prev = cl;
            Head->next = cl;
            return cl->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            Cache[key]->value = value;
        }
        else{
            if(Cache.size() == MaxCapacity){
                int EvictedKey = Tail->prev->key;
                Cache.erase(EvictedKey);
                shared_ptr<CacheLine> last = Tail->prev;
                last->prev->next = Tail;
                Tail->prev = last->prev;
                last = nullptr;
            }
            shared_ptr<CacheLine> first = make_shared<CacheLine>(key, value);
            first->next = Head->next;
            first->prev = Head;
            Head->next->prev = first;
            Head->next = first;
            Cache[key] = first;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
