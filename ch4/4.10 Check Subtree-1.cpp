/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        ostringstream oss1, oss2;
        preOrder(t1, oss1);
        preOrder(t2, oss2);
        return oss1.str().find(oss2.str()) != string::npos;
    }
private:
    void preOrder(TreeNode* root, ostringstream &oss)
    {
        if(root == nullptr){
            oss << "n" << endl;
            return;
        }
        else oss << root->val << endl;
        preOrder(root->left, oss);
        preOrder(root->right, oss);        
    }
};
