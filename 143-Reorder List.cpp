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
        if(!head||!head->next)
            return;
        ListNode *mid=head,*next=head,*prev=NULL;
        while(next&&next->next)
            mid=mid->next,next=next->next->next;
        next=mid;
        mid=mid->next;
        next->next=NULL;
        while(mid)
        {
            next=mid->next;
            mid->next=prev;
            prev=mid;
            mid=next;
        }
        mid=head;
        while(mid&&prev)
        {
            next=mid->next;
            mid->next=prev;
            mid=next;
            next=prev->next;
            prev->next=mid;
            prev=next;
        }
    }
};