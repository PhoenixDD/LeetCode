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
    pair<bool,pair<ListNode*,ListNode*>> reverseK(ListNode* head, int k) 
    {
        ListNode *prev=NULL,*next=NULL;
        while(head&&k--)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return {k<=0,{prev,head}};
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        pair<bool,pair<ListNode*,ListNode*>> temp=reverseK(head,k);
        if(!temp.first)
        {
            temp=reverseK(temp.second.first,k);
            return temp.second.first;
        }
        ListNode* result=temp.second.first,*prev;
        int kTemp;
        while(temp.second.first)
        {
            kTemp=k;
            while(--kTemp&&temp.first)
                temp.second.first=temp.second.first->next;
            prev=temp.second.first;
            temp=reverseK(temp.second.second,k);
            if(!temp.first)
            {
                temp=reverseK(temp.second.first,k);
                prev->next=temp.second.first;
                return result;
            }
            prev->next=temp.second.first;
        }
        return result;
    }
};