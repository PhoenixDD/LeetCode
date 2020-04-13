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
        ListNode* Dummy=new ListNode(0);
        Dummy->next=head;
        ListNode* anchor=head;
        while(head)
        {
            if(head->val!=9)
                anchor=head;
            head=head->next;
        }
        head=anchor->next;
        while(head)
            head->val=0,head=head->next;
        if(anchor->val==9)
        {
            Dummy->val=1,anchor->val=0;
            return Dummy;
        }
        anchor->val++;
        return Dummy->next;
            
    }
};