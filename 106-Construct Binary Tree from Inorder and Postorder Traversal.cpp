/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int post_ind;
    unordered_map<int,int> indexes;
    TreeNode* build(vector<int>& post, vector<int>& in,int start,int end)
    {
        if(start>end)
            return NULL;
        TreeNode* node=new TreeNode(post[post_ind--]);
        node->right=build(post,in,indexes[node->val]+1,end);
        node->left=build(post,in,start,indexes[node->val]-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        post_ind=inorder.size()-1;
        indexes.reserve(inorder.size());
        for(int i=0;i<inorder.size();i++)
            indexes[inorder[i]]=i;
        return build(postorder,inorder,0,inorder.size()-1);
    }
};