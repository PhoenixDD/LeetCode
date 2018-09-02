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
    int kth(TreeNode* root, int &k)
    {
        if(!root)
            return INT_MIN;
        int num=INT_MIN;
        num=kth(root->left,k);
        k--;
        if(!k)
            return root->val;
        return num==INT_MIN?kth(root->right,k):num;
    }
    int kthSmallest(TreeNode* root, int k)
    {
        return kth(root,k);
    }
};