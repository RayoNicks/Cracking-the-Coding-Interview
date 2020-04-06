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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* runner;
        while(curr != nullptr){
            runner = curr;
            while(runner->next != nullptr){
                if(runner->next->val == curr->val){
                    runner->next = runner->next->next;
                }
                else runner = runner->next;
            }
            curr = curr->next;
        }
        return head;
    }
};
