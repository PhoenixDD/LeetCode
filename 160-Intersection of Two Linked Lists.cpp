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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *a=headA,*b=headB;
        int len=0;
        while(a)
            len++,a=a->next;
        while(b)
            len--,b=b->next;
        a=headA,b=headB;
        if(len<0)
            while(len)
                b=b->next,len++;
        if(len>0)
            while(len)
                a=a->next,len--;
        while(a!=b)
            a=a->next,b=b->next;
        return a;
    }
};