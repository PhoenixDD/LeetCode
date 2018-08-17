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
        if(!head)
            return NULL;
        RandomListNode *node=head;
        while(node)
        {
            RandomListNode *temp=new RandomListNode(node->label);
            temp->next=node->next;
            node->next=temp;
            node=temp->next;
        }
        node=head;
        while(node)
        {
            if(node->random)
                node->next->random=node->random->next;
            node=node->next->next;
        }
        node=head;
        RandomListNode *node1=head->next,*node2=head->next;
        while(node&&node1)
        {
            if(node->next)
                node->next=node->next->next;
            if(node1->next)
                node1->next=node1->next->next;
            node=node->next;
            node1=node1->next;
        }            
        return node2;
    }
};