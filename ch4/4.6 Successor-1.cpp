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
private:
    bool flag = false;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr) return nullptr;
        TreeNode* ret = inorderSuccessor(root->left, p);
        if(ret != nullptr) return ret;
        if(root == p) flag = true;
        else if(flag){
            ret = root;
            flag = false;
            return ret;
        }
        return inorderSuccessor(root->right, p);
    }
};
