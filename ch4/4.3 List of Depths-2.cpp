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
        deque<TreeNode*> dq;
        if(tree != nullptr){
            dq.push_back(tree);
        }
        while(!dq.empty()){
            ListNode* tail = nullptr;
            deque<TreeNode*> dqNext;
            while(!dq.empty()){
                TreeNode* front = dq.front();
                dq.pop_front();
                if(front == nullptr) continue;
                if(tail == nullptr){
                    tail = new ListNode(front->val);
                    vecList.push_back(tail);
                }
                else{
                    tail->next = new ListNode(front->val);
                    tail = tail->next;
                }
                dqNext.push_back(front->left);
                dqNext.push_back(front->right);
            }
            dq = dqNext;
        }
        return vecList;
    }
};
