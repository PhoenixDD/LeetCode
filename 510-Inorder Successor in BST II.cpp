/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) 
    {
        if(node->right)
        {
            node=node->right;
            while(node&&node->left)
                node=node->left;
            return node;
        }
        else
        {
            int toFind=node->val;
            while(node->parent&&node->val<=toFind)
                node=node->parent;
            if(node->val<toFind&&(!node->right||node->right->val<=toFind))
                return NULL;
            return node->val==toFind?NULL:node;
            
        }
    }
};