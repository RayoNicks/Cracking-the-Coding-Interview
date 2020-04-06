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
        int len = ListLength(head);
        return isPalindrome(head, len).bPalindrome;
    }
private:
    struct Result
    {
        bool bPalindrome;
        ListNode* corr;
    };
    int ListLength(ListNode* head)
    {
        int ret = 0;
        while(head != nullptr){
            ret++;
            head = head->next;
        }
        return ret;
    }
    Result isPalindrome(ListNode* head, int length)
    {
        Result res;
        if(length == 0){
            res.bPalindrome = true;
            res.corr = nullptr;
        }
        else if(length == 1){//odd number of nodes
            res.bPalindrome = true;
            res.corr = head->next;
        }
        else if(length == 2){//even number of nodes
            res.bPalindrome = head->val == head->next->val;
            res.corr = head->next->next;
            return res;
        }
        else{
            res = isPalindrome(head->next, length - 2);
            if(res.bPalindrome && head->val == res.corr->val);
            else res.bPalindrome = false;
            res.corr = res.corr->next;
        }
        return res;
    }
};
