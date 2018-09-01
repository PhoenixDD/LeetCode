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
        return !root?-1:1+height(root->left);
    }
    int countNodes(TreeNode* root,int h=-2)
    {
        int hl,hr;
        if(h==-2)
            hl=height(root);
        else 
            hl=h;
        if(hl==-1)
            return 0;
        hr=height(root->right);
        return hr==hl-1?(1<<hl)+countNodes(root->right,hr):(1<<hl-1)+countNodes(root->left,hl-1);
    }
};