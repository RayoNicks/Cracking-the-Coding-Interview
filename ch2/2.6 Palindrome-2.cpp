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
        vector<ListNode*> vecPart;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            vecPart.push_back(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr){//odd number of nodes
            slow = slow->next;
        }
        while(slow != nullptr){
            if(slow->val != vecPart.back()->val) return false;
            slow = slow->next;
            vecPart.pop_back();
        }
        return true;
    }
};
