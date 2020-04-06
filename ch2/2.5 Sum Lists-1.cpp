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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode** curr = &head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            *curr = new ListNode(l1->val + l2->val + carry);
            carry = (*curr)->val / 10;
            (*curr)->val %= 10;
            curr = &(*curr)->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            *curr = new ListNode(l1->val + carry);
            carry = (*curr)->val / 10;
            (*curr)->val %= 10;
            curr = &(*curr)->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            *curr = new ListNode(l2->val + carry);
            carry = (*curr)->val / 10;
            (*curr)->val %= 10;
            curr = &(*curr)->next;
            l2 = l2->next;
        }
        if(carry != 0){
            *curr = new ListNode(carry);
        }
        return head;
    }
};
