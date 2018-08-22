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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow=head,*fast=head;
        do
        {
            if(fast&&fast->next&&slow)
                fast=fast->next->next,slow=slow->next;
            else
                return false;
        }while(slow!=fast);
        return true;
    }
};