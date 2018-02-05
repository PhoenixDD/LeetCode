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
        if(head==NULL||head->next==NULL)
            return head;
        int counter=0;
        ListNode* head1=head;
        while(1)
        {
            if(head1->next==NULL)
            {
                head1->next=head;
                counter++;
                break;
            }
            head1=head1->next;
            counter++;
        }
        k%=counter;
        counter-=k;
        counter--;
        head1=head;
        while(counter)
        {
            head1=head1->next;
            counter--;
        }
        head=head1->next;
        head1->next=NULL;
        return head;
    }
};