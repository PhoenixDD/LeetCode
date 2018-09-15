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
    ListNode* next,*newhead;
    bool flag;
    ListNode* reverse(ListNode* head,int k)
    {
        if(k==1||!head->next)
        {
            if(k!=1)
                flag=true;
            newhead=head;
            next=head->next;
            return head;
        }
        return reverse(head->next,k-1)->next=head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* Dummy=new ListNode(-1),*prev=Dummy;
        Dummy->next=head;
        while(head)
        {
            flag=false;
            reverse(head,k)->next=next;
            if(flag)
                reverse(newhead,k)->next=next;
            prev->next=newhead;
            prev=head;
            head=next;
        }
        return Dummy->next;
    }
};