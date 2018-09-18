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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode* Dummy=new ListNode(-1);
        Dummy->next=head;
        ListNode* pre=Dummy,*cur,*next;
        while(m!=1)
            pre=pre->next,m--,n--;
        cur=pre->next;
        while(n!=1)
        {
            next=cur->next;
            cur->next=next->next;
            next->next=pre->next;
            pre->next=next;
            n--;
        }
        return Dummy->next;
    }
};