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
    ListNode* merge(ListNode *left,ListNode *right)
    {
        if(!left)
            return right;
        if(!right)
            return left;
        if(left->val<right->val)
        {
            left->next=merge(left->next,right);
            return left;
        }
        else
        {
            right->next=merge(left,right->next);
            return right;
        }
    }
    ListNode* sortList(ListNode* head)
    {
        if(!head)
            return head;
        if(!head->next)
            return head;
        
        ListNode *first=head,*second=head;
        while(first->next&&first->next->next)
            first=first->next->next,second=second->next;
        first=second->next;
        second->next=NULL;
        ListNode *left=sortList(head);
        ListNode *right=sortList(first);
        return merge(left,right);
        
    }
};