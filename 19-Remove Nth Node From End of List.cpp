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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int counter=0;
        ListNode *ptr2=new ListNode(-1),*ptr1=ptr2;
        ptr2->next=head;
        while(head)
        {
            head=head->next;
            counter++;
            if(counter>n)
                ptr2=ptr2->next;
        }
        ptr2->next=ptr2->next->next;
        return ptr1->next;
        
    }
};