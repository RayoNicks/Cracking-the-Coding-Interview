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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int lHgt, rHgt;
        bool bLeft = checkBalance(root->left, lHgt);
        bool bRight = checkBalance(root->right, rHgt);
        bool bRoot = abs(lHgt - rHgt) <= 1;
        return bLeft && bRight && bRoot;
    }
private:
    bool checkBalance(TreeNode *root, int &height)
    {
        if(root == nullptr){
            height = -1;
            return true;
        }
        int lHgt, rHgt;
        bool bLeft = checkBalance(root->left, lHgt);
        bool bRight = checkBalance(root->right, rHgt);
        bool bRoot = abs(lHgt - rHgt) <= 1;
        height = lHgt > rHgt ? lHgt : rHgt;
        height++;
        return bLeft && bRight && bRoot; 
    }
};
