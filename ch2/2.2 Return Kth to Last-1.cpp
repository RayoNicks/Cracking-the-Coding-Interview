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
    int kthToLast(ListNode* head, int k) {
        int iTh = 0;
        return doKthToLast(head, k, iTh)->val;
    }
private:
    ListNode* doKthToLast(ListNode* head, int k, int &iTh)
    {
        if(head == nullptr) return nullptr;
        ListNode* p = doKthToLast(head->next, k, iTh);
        iTh++;
        if(iTh == k) return head;
        return p;
    }
};
