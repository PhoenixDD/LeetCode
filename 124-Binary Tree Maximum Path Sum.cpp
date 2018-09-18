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
    int Max=INT_MIN;
    int maxPath(TreeNode* root)
    {
        if(!root)
            return 0;
        int left=max(0,maxPath(root->left)),right=max(0,maxPath(root->right));
        Max=max(Max,root->val+left+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) 
    {
        maxPath(root);
        return Max;
    }
};