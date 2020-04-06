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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!exist(root, p) || !exist(root, q)) return nullptr;
        return CommonAncestor(root, p, q);
    }
private:
    bool exist(TreeNode *root, TreeNode *n)
    {
        if(root == nullptr) return false;
        else if(root == n) return true;
        else return exist(root->left, n) || exist(root->right, n);
    }
    TreeNode* CommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == p || root == q) return root;
        bool bPLeft = exist(root->left, p);
        bool bQLeft = exist(root->left, q);
        if(bPLeft && bQLeft){
            return CommonAncestor(root->left, p, q);
        }
        else if(!bPLeft && !bQLeft){
            return CommonAncestor(root->right, p, q);
        }
        else return root;
    }
};
