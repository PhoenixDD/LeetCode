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
        ListNode *head=new ListNode(INT_MIN),*res=head;
        while(left&&right)
        {
            if(left->val<right->val)
                head->next=left,left=left->next;
            else
                head->next=right,right=right->next;
            head=head->next;
        }
        if(left)
            head->next=left;
        else if(right)
            head->next=right;
        return res->next;
            
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