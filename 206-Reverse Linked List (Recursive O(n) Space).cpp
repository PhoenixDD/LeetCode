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
    ListNode* head2;
    ListNode* reverse(ListNode* head)
    {
        if(!head->next)
        {
            head2=head;
            return head;
        }
        return reverse(head->next)->next=head;
    }
    ListNode* reverseList(ListNode* head) 
    {
        if(!head||!head->next)
            return head;
        reverse(head)->next=NULL;
        return head2;
    }
};