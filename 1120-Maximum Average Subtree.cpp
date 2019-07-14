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
    double result=0;
    pair<int,int> dfs(TreeNode* root)
    {
        if(!root)
            return {0,0};
        pair<int,int> left=dfs(root->left),right=dfs(root->right);
        int n=left.second+right.second+1,s=left.first+right.first+root->val;
        result=max(result,(double)s/n);
        return {s,n};
    }
    double maximumAverageSubtree(TreeNode* root) 
    {
        dfs(root);
        return result;
    }
};