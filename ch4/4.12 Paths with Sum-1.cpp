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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        int rootCnt = pathCnt(root, sum, 0);
        int leftCnt = pathSum(root->left, sum);
        int rightCnt = pathSum(root->right, sum);
        return rootCnt + leftCnt + rightCnt;
    }
private:
    int pathCnt(TreeNode* root, const int sum, int part)
    {
        int paths = 0;
        if(root == nullptr) return 0;
        part += root->val;
        if(part == sum) paths++;
        paths += pathCnt(root->left, sum, part);
        paths += pathCnt(root->right, sum, part);
        return paths;
    }
};
