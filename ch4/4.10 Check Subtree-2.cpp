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
        if(t2 == nullptr) return true;
        else if(t1 == nullptr) return false;
        else if(t1->val == t2->val && matchTree(t1, t2)) return true;
        else return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
    bool matchTree(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == nullptr && t2 == nullptr) return true;
        else if(t1 == nullptr || t2 == nullptr) return false;
        else if(t1->val != t2->val) return false;
        else return matchTree(t1->left, t2->left) && matchTree(t1->right, t2->right);
    }
};
