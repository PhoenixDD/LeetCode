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
    int maximum=INT_MIN;
    int recur(TreeNode* root)
    {
        if(!root)
            return 0;
        int l=max(0,recur(root->left));
        int r=max(0,recur(root->right));
        maximum=max(maximum,l+r+root->val);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) 
    {
        recur(root);
        return maximum;
    }
};