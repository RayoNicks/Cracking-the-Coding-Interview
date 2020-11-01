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
    pair<TreeNode*, TreeNode*> convert(TreeNode* root)
    {
        TreeNode *head = root, *tail = root;
        if(root->left != nullptr){
            pair<TreeNode*, TreeNode*> LeftList = convert(root->left);
            LeftList.second->right = root;
            root->left = nullptr;
            head = LeftList.first;
        }
        if(root->right != nullptr){
            pair<TreeNode*, TreeNode*> RightList = convert(root->right);
            RightList.first->left = nullptr;
            root->right = RightList.first;
            tail = RightList.second;
        }
        return make_pair(head, tail);
    }
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if(root == nullptr) return nullptr;
        else return convert(root).first;
    }
};
