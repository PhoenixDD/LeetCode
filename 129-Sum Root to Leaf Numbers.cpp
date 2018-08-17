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
    int sumNumbers(TreeNode* root,int num)
    {
        if(!root->left&&!root->right)
            return num*10+root->val;
        if(root->left&&root->right)
            return sumNumbers(root->left,num*10+root->val)+sumNumbers(root->right,num*10+root->val);
        else if(root->left)
            return sumNumbers(root->left,num*10+root->val);
        else 
            return sumNumbers(root->right,num*10+root->val);
    }
    int sumNumbers(TreeNode* root)
    {
        if(!root)
            return 0;
        return sumNumbers(root,0);
    }
};