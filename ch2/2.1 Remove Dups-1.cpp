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
        ListNode** curr = &head;//currָ��ǰһ���ڵ��ָ����
        while(*curr != nullptr){
            if(sValue.find((*curr)->val) == sValue.end()){
                sValue.insert((*curr)->val);
                curr = &(*curr)->next;//�ƶ����½ڵ�
            }
            else{
                *curr = (*curr)->next;//ɾ���ڵ�
            }
        }
        return head;
    }
};
