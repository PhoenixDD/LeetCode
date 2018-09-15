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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *Dummy=new ListNode(-1);
        Dummy->next=head;
        head=Dummy;
        int val;
        while(Dummy->next&&Dummy->next->next)
        {
            if(Dummy->next->val==Dummy->next->next->val)
            {
                val=Dummy->next->val;
                while(Dummy->next&&Dummy->next->val==val)
                    Dummy->next=Dummy->next->next;
            }
            else
                Dummy=Dummy->next;
        }
        return head->next;
    }
};