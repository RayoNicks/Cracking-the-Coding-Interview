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
    bool isPalindrome(ListNode* head) {
        ListNode* reverse = nullptr;
        ListNode* node;
        ListNode* curr = head;
        while(curr != nullptr){
            node = new ListNode(curr->val);
            node->next = reverse;
            reverse = node;
            curr = curr->next;
        }
        return isEqual(head, reverse);
    }
private:
    bool isEqual(ListNode* head, ListNode* reverse)
    {
        while(head != nullptr && reverse != nullptr){
            if(head->val != reverse->val) return false;
            head = head->next;
            reverse = reverse->next;
        }
        return head == nullptr && reverse == nullptr;
    }
};
