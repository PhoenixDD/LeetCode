/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head=NULL,*prev=NULL;
    void getDll(Node* root)
    {
        if(!root)
            return;
        getDll(root->left);
        if(prev)
            prev->right=root,root->left=prev;
        prev=root;
        getDll(root->right);
    }
    Node* treeToDoublyList(Node* root) 
    {
        Node* temp=root;
        while(temp)
            head=temp,temp=temp->left;
        getDll(root);
        if(prev)
            prev->right=head;
        if(head)
            head->left=prev;
        return head;
    }
};