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
    bool isPalindrome(ListNode* head)
    {
        if(!head)
            return true;
        ListNode *curr=head,*mid=head,*prev=NULL;
        while(curr&&curr->next&&curr->next->next)
            curr=curr->next->next,mid=mid->next;
        curr=mid->next;
        while(curr)
        {
            mid=curr->next;
            curr->next=prev;
            prev=curr;
            curr=mid;
        }
        while(prev&&head&&head->val==prev->val)
            prev=prev->next,head=head->next;
        if(!prev)
            return true;
        return false;
    }
};