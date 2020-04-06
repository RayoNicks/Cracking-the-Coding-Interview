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
        ListNode beforeStartNode(0), afterStartNode(0);
        ListNode* beforeEnd = &beforeStartNode;
        ListNode* afterEnd = &afterStartNode;
        ListNode* iter = head;
        while(iter != nullptr){
            if(iter->val < x){
                beforeEnd->next = iter;
                beforeEnd = iter;
            }
            else{
                afterEnd->next = iter;
                afterEnd = iter;
            }
            iter = iter->next;
        }
        afterEnd->next = nullptr;
        if(beforeStartNode.next == nullptr){
            return afterStartNode.next;
        }
        beforeEnd->next = afterStartNode.next;
        return beforeStartNode.next;
    }
};
