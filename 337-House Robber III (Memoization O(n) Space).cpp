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
    unordered_map<TreeNode*,int> memo;
    int rob(TreeNode* &root) 
    {
        if(!root)
            return 0;
        if(memo.count(root))
            return memo[root];
        int val=0;
        if(root->left)
            val+=rob(root->left->right)+rob(root->left->left);
        if(root->right)
            val+=rob(root->right->right)+rob(root->right->left);
        return memo[root]=max(root->val+val,rob(root->left)+rob(root->right));
    }
};