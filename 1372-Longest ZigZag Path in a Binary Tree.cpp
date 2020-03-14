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
    int zigzag(TreeNode* root, bool right=false)
    {
        if(!root)
            return 0;
        int l=zigzag(root->left,true),r=zigzag(root->right,false);
        Max=max(Max,max(1+l,1+r));
        return 1+(right?r:l);
    }
    int longestZigZag(TreeNode* root) 
    {
        zigzag(root);
        return Max-1;
    }
};