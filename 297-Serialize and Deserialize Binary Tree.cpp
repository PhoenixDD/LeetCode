/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(!root)
            return "#";
        return to_string(root->val)+','+serialize(root->left)+','+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data,int &i)
    {
        int next=data.find_first_of(',',i);
        string val=data.substr(i,next-i);
        i=next+1;
        if(val=="#")
            return NULL;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=deserialize(data,i);
        root->right=deserialize(data,i);
        return root;        
    }
    TreeNode* deserialize(string data)
    {
        int i=0;
        return deserialize(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));