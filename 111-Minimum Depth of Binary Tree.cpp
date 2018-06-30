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
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int left=height(root->left);
        if(left==-1)
            return -1;
        int right=height(r/**
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
    int minDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        if(root->right&&root->left)
            return 1+min(minDepth(root->left),minDepth(root->right));
        else if(root->right)
            return 1+minDepth(root->right);
        else if(root->left)
            return 1+minDepth(root->left);
        else
            return 1;
    }
};