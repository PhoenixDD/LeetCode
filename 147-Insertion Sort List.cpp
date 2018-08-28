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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *start=head,*Dummy=new ListNode(-1),*prev=Dummy;
        Dummy->next=head;
        bool done=false;
        while(start)
        {
            for(ListNode *temp=Dummy;temp!=prev;temp=temp->next)
            {
                if(temp->next->val>start->val)
                {
                    prev->next=start->next;
                    start->next=temp->next;
                    temp->next=start;
                    start=prev->next;
                    done=true;
                    break;
                }
            }
            if(!done)
                prev=start,start=start->next;
            else
                done=false;
        }
        return Dummy->next;
    }
};