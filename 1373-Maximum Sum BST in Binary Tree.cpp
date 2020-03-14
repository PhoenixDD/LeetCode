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
    int result=0;
    int BSTSearch(TreeNode* root)
    {
        if(!root)
            return 0;
        int l=BSTSearch(root->left),r=BSTSearch(root->right);
        if(l!=INT_MIN&&r!=INT_MIN&&(!root->left||root->left->val<root->val)&&(!root->right||root->right->val>root->val))
        {
            result=max(result,root->val+l+r);
            return root->val+l+r;
        }
        return INT_MIN;
    }
    int maxSumBST(TreeNode* root) 
    {
        BSTSearch(root);
        return result;
    }
};