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
    bool isValidBST(TreeNode* root) {
        return checkValidBST(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool checkValidBST(TreeNode *root, const long long min, const long long max)
    {
        if(root == nullptr) return true;
        if(!checkValidBST(root->left, min, root->val)) return false;
        if(root->val <= min || root->val >= max) return false;
        return checkValidBST(root->right, root->val, max);
    }
};
