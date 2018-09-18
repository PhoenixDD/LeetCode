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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* Dummy=new ListNode(-1),*head2=new ListNode(-1),*temp=head2;
        Dummy->next=head;
        head=Dummy;
        while(Dummy->next)
        {
            if(Dummy->next->val>=x)
            {
                temp->next=Dummy->next;
                Dummy->next=Dummy->next->next;
                temp=temp->next;
                temp->next=NULL;
            }
            else
                Dummy=Dummy->next;
        }
        Dummy->next=head2->next;
        return head->next;
    }
};