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
    int Max=0;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int left=helper(root->left),right=helper(root->right);
        Max=max(Max,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        helper(root);
        return Max;
    }
};