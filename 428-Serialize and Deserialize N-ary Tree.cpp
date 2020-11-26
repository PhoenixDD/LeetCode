/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    string serialize(Node* root) 
    {
        if(!root)
            return "#";
        if(root->children.empty())
            return to_string(root->val)+','+"#";
        string result=to_string(root->val)+",";
        for(Node* n:root->children)
            result+=serialize(n)+",";
        return result+"#";
    }
    Node* deserialize(string &data,int &i)
    {
        int j=data.find(',',i);
        string val=data.substr(i,j-i);
        i=j+1;
        if("#"==val)
            return NULL;
        Node* root=new Node(stoi(val));
        while(i<data.length())
        {
            root->children.push_back(deserialize(data,i));
            if(!root->children.back())
            {
                root->children.pop_back();
                return root;
            }
        }
        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data)
    {
        int i=0;
        return deserialize(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));