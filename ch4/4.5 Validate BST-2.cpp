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
    int* pElt = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(!isValidBST(root->left)) return false;
        if(pElt == nullptr){
            pElt = new int(root->val);
        }
        else if(root->val <= *pElt){
            return false;
        }
        else{
            *pElt = root->val;
        }
        return isValidBST(root->right);
    }
};
