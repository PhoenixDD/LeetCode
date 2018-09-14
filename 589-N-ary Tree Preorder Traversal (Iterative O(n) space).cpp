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
    vector<int> preorder(Node* root) 
    {
        vector<int> result;
        stack<Node*> s;
        s.push(root);
        Node* top;
        while(!s.empty())
        {
            top=s.top(),s.pop();
            if(top)
            {
                result.push_back(top->val);
                for(int i=top->children.size()-1;i>=0;i--)
                    top->children[i]?s.push(top->children[i]):void();
            }
        }
        return result;
    }
};