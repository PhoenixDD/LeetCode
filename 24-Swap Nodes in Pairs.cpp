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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* Dummy=new ListNode(-1),*prev=Dummy,*next;
        Dummy->next=head;
        while(head&&head->next)
        {
            next=head->next->next;
            prev->next=head->next;
            head->next->next=head;
            head->next=next;
            prev=head;
            head=next;
        }
        return Dummy->next;
    }
};