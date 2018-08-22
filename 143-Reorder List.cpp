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
    void reorderList(ListNode* head)
    {
        if(!head||!head->next||!head->next->next)
            return;
        ListNode *start=head,*mid=head,*curr;
        while(start&&start->next)
            start=start->next->next,mid=mid->next;
        start=mid;
        mid=mid->next;
        start->next=NULL;
        while(mid)
        {
            curr=mid;
            mid=mid->next;
            curr->next=start;
            start=curr;
        }
        while(head&&curr)
        {
            mid=head->next;
            head->next=curr;
            start=curr->next;
            curr->next=mid;
            head=mid;
            curr=start;
        }
        if(!curr)
                head->next=NULL;
    }
};