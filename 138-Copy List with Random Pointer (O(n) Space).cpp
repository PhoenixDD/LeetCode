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
        unordered_map<RandomListNode*,RandomListNode*> map;
        RandomListNode* temp=head,*copy;
        while(temp)
            copy=new RandomListNode(temp->label),map[temp]=copy,temp=temp->next;
        temp=head;
        while(temp)
        {
            map[temp]->next=temp->next?map[temp->next]:NULL;
            map[temp]->random=temp->random?map[temp->random]:NULL;
            temp=temp->next;
        }
        return map[head];
    }
};