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
        hashSum.insert(pair<int, int>(0, 1));
        pathCnt(root, sum);
        return cnt;
    }
private:
    int cnt = 0, part = 0;
    unordered_map<int, int> hashSum;
    void pathCnt(TreeNode* root, const int sum)
    {
        if(root == nullptr) return;
        part += root->val;
        unordered_map<int, int>::iterator iter;
        if((iter = hashSum.find(part - sum)) != hashSum.end()){
            cnt += iter->second;
        }
        hashSum[part]++;
        pathCnt(root->left, sum);
        pathCnt(root->right, sum);
        hashSum[part]--;
        if(hashSum[part] == 0) hashSum.erase(part);
        part -= root->val;
    }
};
