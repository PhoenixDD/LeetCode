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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head||!head->next)
            return head;
        int size=0;
        ListNode *end=head,*temp,*res;
        while(end->next)
            end=end->next,size++;
        size++;
        k%=size;
        if(k==0)
            return head;
        temp=head;
        for(int i=0;i<size-k-1;i++)
            temp=temp->next;
        end->next=head;
        res=temp->next;
        temp->next=NULL;
        return res;
    }
};