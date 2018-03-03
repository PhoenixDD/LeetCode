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
    ListNode *head1,*temp,*nxt;
    void reverse(ListNode* head,int m,int n)
    {
        if(m==n)
        {
            head1=head;
            temp=head1;
            nxt=head1->next;
        }
        else
        {
            reverse(head->next,m+1,n);
            temp->next=head;
            temp=temp->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {   
        if(!head)
            return head;
        ListNode* temp1=new ListNode(-1),*result;
        temp1->next=head;
        result=temp1;
        int index=1;
        while(index<m)
        {
            temp1=temp1->next;
            index++;
        }
        reverse(temp1->next,m,n);
        temp1->next=head1;
        temp->next=nxt;
        return result->next;
    }
};