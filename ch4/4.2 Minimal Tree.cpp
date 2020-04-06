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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size());
    }
private:
    TreeNode* createBST(const vector<int> &vec, size_t begin, size_t end)
    {
        if(begin == end) return nullptr;
        size_t mid = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = createBST(vec, begin, mid);
        root->right = createBST(vec, mid + 1, end);
        return root;
    }
};
