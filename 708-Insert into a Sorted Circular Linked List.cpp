/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) 
    {
        if(!head)
        {
            Node *temp=new Node(insertVal);
            temp->next=temp;
            return temp;
        }
        Node* sNode=NULL,*prevSNode=NULL,*temp=head,*prev=NULL,*mNode=NULL;
        do
        {
            if(!sNode||temp->val<sNode->val)
            {
                prevSNode=prev;
                sNode=temp;
            }
            if(!mNode||temp->val>=mNode->val)
                mNode=temp;
            prev=temp;
            temp=temp->next;
        }while(temp!=head);
        if(sNode==head)
            prevSNode=prev;
        temp=sNode;
        prev=prevSNode;
        while(temp)
        {
            if(insertVal<=temp->val)
            {
                prev->next=new Node(insertVal);
                prev->next->next=temp;
                return head;
            }
            else if(temp==mNode)
            {
                Node* t=temp->next;
                temp->next=new Node(insertVal);
                temp->next->next=t;
                return head; 
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};