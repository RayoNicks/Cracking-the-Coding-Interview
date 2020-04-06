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
        return doAddTwoNumbers(l1, l2, 0);
    }
private:
    ListNode* doAddTwoNumbers(ListNode* l1, ListNode* l2, int carry)
    {
        if(l1 == nullptr && l2 == nullptr && carry == 0){
            return nullptr;
        }
        ListNode* res = new ListNode(carry);
        if(l1 != nullptr){
            res->val += l1->val;
        }
        if(l2 != nullptr){
            res->val += l2->val;
        }
        carry = res->val / 10;
        res->val %= 10;
        res->next = doAddTwoNumbers(l1 ? l1->next : nullptr,
                                    l2 ? l2->next : nullptr,
                                    carry);
        return res;
    }
};
