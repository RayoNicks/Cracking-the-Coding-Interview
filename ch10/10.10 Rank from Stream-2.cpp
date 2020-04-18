class StreamRank {
private:
    struct Node
    {
        int value, leftSubSize, dup;
        Node* left;
        Node*right;
        Node(int value) : value(value), leftSubSize(0), dup(1), left(nullptr), right(nullptr){};
    };
    Node* root;
public:
    StreamRank() {
        root = nullptr;
    }
    
    void track(int x) {
        Node** curr = &root;
        while(*curr != nullptr){
            if(x < (*curr)->value){
                (*curr)->leftSubSize++;
                curr = &(*curr)->left;
            }
            else if(x > (*curr)->value){
                curr = &(*curr)->right;
            }
            else{
                (*curr)->dup++;
                return;
            }
        }
        *curr = new Node(x);
        return;
    }
    
    int getRankOfNumber(int x) {
        Node** curr = &root;
        int ret = 0;
        while(*curr != nullptr){
            if(x < (*curr)->value){
                curr = &(*curr)->left;
            }
            else if(x > (*curr)->value){
                ret += (*curr)->leftSubSize + (*curr)->dup;
                curr = &(*curr)->right;
            }
            else{
                ret += (*curr)->leftSubSize + (*curr)->dup;
                return ret;
            }
        }
        return ret;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
