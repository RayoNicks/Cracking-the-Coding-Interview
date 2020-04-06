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
        TraverseInOrder(root);
        for(size_t i = 1; i < vec.size(); i++)
        {
            if(vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
private:
    vector<int> vec;
    void TraverseInOrder(TreeNode *root)
    {
        if(root == nullptr) return;
        TraverseInOrder(root->left);
        vec.push_back(root->val);
        TraverseInOrder(root->right);
    }
};
