/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> result;
    void helper(Node* root)
    {
        if(!root)
            return;
        result.push_back(root->val);
        for(Node *&i:root->children)
            helper(i);
        return;
    }
    vector<int> preorder(Node* root) 
    {
        helper(root);
        return result;
    }
};