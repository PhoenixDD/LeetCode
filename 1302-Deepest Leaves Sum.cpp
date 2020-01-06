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
    int Max=-1,result=0;
    void dfs(TreeNode* root,int d=0)
    {
        if(!root)
            return;
        if(d>Max)
            Max=d,result=root->val;
        else if(d==Max)
            result+=root->val;
        dfs(root->left,d+1),dfs(root->right,d+1);
    }
    int deepestLeavesSum(TreeNode* root) 
    {
        dfs(root);
        return result;
    }
};