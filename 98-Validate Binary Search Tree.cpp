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
    bool valid(TreeNode* root,TreeNode* less,TreeNode* more)
    {
        return !root||((!less||root->val<less->val)&&(!more||root->val>more->val)&&valid(root->right,less,root)&&valid(root->left,root,more));
    }
    bool isValidBST(TreeNode* root)
    {
        return valid(root,NULL,NULL);
    }
};