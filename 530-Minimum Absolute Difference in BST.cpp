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
    int Min=INT_MAX;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(prev)
            Min=min(Min,root->val-prev->val);
        prev=root;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) 
    {
        inorder(root);
        return Min;
    }
};