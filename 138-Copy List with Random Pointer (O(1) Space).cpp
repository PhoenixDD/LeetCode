/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        RandomListNode *temp=head,*copy,*temp2,*head2;
        while(temp)
        {
            copy=new RandomListNode(temp->label);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        while(temp)
        {
            temp->next->random=temp->random?temp->random->next:NULL;
            temp=temp->next->next;
        }
        temp=head;
        head2=temp2=head?head->next:NULL;
        while(temp)
        {
            temp->next=temp->next->next;
            temp2->next=temp2->next?temp2->next->next:NULL;
            temp=temp->next,temp2=temp2->next;
        }
        return head2;
    }
};