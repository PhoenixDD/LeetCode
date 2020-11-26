/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double Max=0;
    int dfs(TreeNode* root,double &sum)
    {
        if(!root)
            return 0;
        double s=0;
        int l=dfs(root->left,s),r=dfs(root->right,s);
        sum=s+root->val;
        Max=max(sum/(1+l+r),Max);
        return 1+l+r;
        
    }
    double maximumAverageSubtree(TreeNode* root) 
    {
        double sum;
        dfs(root,sum);
        return Max;
    }
};