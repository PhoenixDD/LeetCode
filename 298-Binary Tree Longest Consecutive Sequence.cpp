/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Max=0;
    int preOrder(TreeNode* root)
    {
        if(!root)
            return 0;
        int l=preOrder(root->left)+1,r=preOrder(root->right)+1;
        if(root->left&&root->left->val!=root->val+1)
            l=1;
        if(root->right&&root->right->val!=root->val+1)
            r=1;
        Max=max(Max,max(l,r));
        return max(l,r);
    }
    int longestConsecutive(TreeNode* root) 
    {
        preOrder(root);
        return Max;
    }
};