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
    ListNode* plusOne(ListNode* head) 
    {
        ListNode* prev=NULL,*cur=head,*next;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        next=cur=prev;
        int carry=1;
        while(cur)
        {
            cur->val+=carry;
            carry=cur->val/10;
            cur->val%=10;
            if(!carry)
                break;
            prev=cur;
            cur=cur->next;
        }
        if(carry)
            prev->next=new ListNode(1);
        prev=NULL,cur=next;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
};