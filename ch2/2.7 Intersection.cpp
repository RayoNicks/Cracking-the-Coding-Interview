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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)     {
        int lenA = ListLength(headA);
        int lenB = ListLength(headB);
        int diff = abs(lenA - lenB);
        ListNode* shorter = lenA < lenB ? headA : headB;
        ListNode* longer = lenA < lenB ? headB : headA;
        while(diff > 0){
            longer = longer->next;
            diff--;
        }
        //书上的这种写法还是很简单的，空链表也适用
        while(shorter != longer){
            shorter = shorter->next;
            longer = longer->next;
        }
        return shorter;
    }
private:
    int ListLength(ListNode* head)
    {
        int ret = 0;
        while(head != nullptr){
            ret++;
            head = head->next;
        }
        return ret;
    }
};
