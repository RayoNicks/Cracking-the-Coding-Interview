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
    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> allSeq;
        enumBSTSequences(root, allSeq);
        return allSeq;
    }
private:
    void enumBSTSequences(TreeNode* root, vector<vector<int>> &allSeq)
    {
        if(root == nullptr){
            allSeq.push_back(vector<int>());
            return;
        }
        vector<vector<int>> lSeq, rSeq;
        enumBSTSequences(root->left, lSeq);
        enumBSTSequences(root->right, rSeq);
        vector<int> lstPre(1, root->val);
        for(size_t i = 0; i < lSeq.size(); i++)
        {
            for(size_t j = 0; j < rSeq.size(); j++)
            {
                weave(lSeq[i], 0, rSeq[j], 0, lstPre, allSeq);
            }
        }
    }
    void weave(vector<int> &lSeq, size_t lIdx, vector<int> &rSeq, size_t rIdx, vector<int> &lstPre, vector<vector<int>> &allSeq)
    {
        if(lIdx == lSeq.size() || rIdx == rSeq.size()){
            allSeq.push_back(lstPre);
            while(lIdx != lSeq.size())
                allSeq.back().push_back(lSeq[lIdx++]);
            while(rIdx != rSeq.size())
                allSeq.back().push_back(rSeq[rIdx++]);
            return;
        }

        lstPre.push_back(lSeq[lIdx]);
        weave(lSeq, lIdx + 1, rSeq, rIdx, lstPre, allSeq);
        lstPre.pop_back();

        lstPre.push_back(rSeq[rIdx]);
        weave(lSeq, lIdx, rSeq, rIdx + 1, lstPre, allSeq);
        lstPre.pop_back();
    }
};
