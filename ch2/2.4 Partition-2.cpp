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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return nullptr;
        ListNode* pHead = head;
        ListNode* pTail = head;
        ListNode* iter = head->next;
        ListNode* next;
        while(iter != nullptr){
            next = iter->next;
            if(iter->val < x){
                iter->next = pHead;
                pHead = iter;
            }
            else{
                pTail->next = iter;
                pTail = iter;
            }
            iter = next;
        }
        pTail->next = nullptr;
        return pHead;
    }
};
