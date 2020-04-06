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
        set<decltype(ListNode::val)> sValue;
        ListNode** curr = &head;//curr指向前一个节点的指针域
        while(*curr != nullptr){
            if(sValue.find((*curr)->val) == sValue.end()){
                sValue.insert((*curr)->val);
                curr = &(*curr)->next;//移动到新节点
            }
            else{
                *curr = (*curr)->next;//删除节点
            }
        }
        return head;
    }
};
