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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow=head,*fast=head;
        do
        {
            if(slow&&fast&&fast->next)
                slow=slow->next,fast=fast->next->next;
            else
                return NULL;
        }while(slow!=fast);
        slow=head;
        while(slow!=fast)
            slow=slow->next,fast=fast->next;
        return slow;
    }
};