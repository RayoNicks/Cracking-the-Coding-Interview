/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> vecList;
        createLevelList(tree, vecList, 0);
        return vecList;
    }
private:
    void createLevelList(TreeNode *root, vector<ListNode*> &vecList, const size_t level)
    {
        if(root == nullptr) return;
        if(level >= vecList.size()){
            vecList.push_back(new ListNode(root->val));
        }
        else{
            ListNode* curr = vecList[level];
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = new ListNode(root->val);
        }
        createLevelList(root->left, vecList, level + 1);
        createLevelList(root->right, vecList, level + 1);
    }
};
