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
        int right=height(root->right);
        if(right==-1||abs(left-right)>1)
            return -1;
        return 1+max(left,right);
        
    }
    bool isBalanced(TreeNode* root)
    {
        return height(root)!=-1;
    }
};