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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* curr=head;
        int count=0;
        while(count!=k&&curr)
            curr=curr->next,count++;
        if(count==k)
        {
            curr=reverseKGroup(curr,k);
            ListNode* next;
            while(count--)
            {
                next=head->next;
                head->next=curr;
                curr=head;
                head=next;
            }
            head=curr;
        }
        return head;
    }
};