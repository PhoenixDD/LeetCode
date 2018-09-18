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
    bool isValidBST(TreeNode* root,TreeNode* Min=NULL,TreeNode* Max=NULL) 
    {
        if(!root)
            return true;
        if(Min&&root->val<=Min->val||Max&&root->val>=Max->val)
            return false;
        return isValidBST(root->left,Min,root)&&isValidBST(root->right,root,Max);
    }
};