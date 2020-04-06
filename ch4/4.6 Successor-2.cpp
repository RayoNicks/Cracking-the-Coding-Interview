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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr) return nullptr;
        if(p->val >= root->val){
            return inorderSuccessor(root->right, p);
        }
        else{
            TreeNode* ret = inorderSuccessor(root->left, p);
            if(ret != nullptr) return ret;
            else return root;
        }
    }
};
