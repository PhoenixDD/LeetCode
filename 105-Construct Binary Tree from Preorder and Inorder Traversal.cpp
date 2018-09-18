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
    int pre_ind=0;
    unordered_map<int,int> indexes;
    TreeNode* build(vector<int>& pre, vector<int>& in,int start,int end)
    {
        if(start>end)
            return NULL;
        TreeNode* node=new TreeNode(pre[pre_ind++]);
        node->left=build(pre,in,start,indexes[node->val]-1);
        node->right=build(pre,in,indexes[node->val]+1,end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        indexes.reserve(inorder.size());
        for(int i=0;i<inorder.size();i++)
            indexes[inorder[i]]=i;
        return build(preorder,inorder,0,inorder.size()-1);
    }
};