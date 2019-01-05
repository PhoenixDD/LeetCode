/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Space Efficient O(logn) Space solution.
class Solution {
public:
    pair<int,int> dfs_greedy(TreeNode* &root)
    {
        if(!root)
            return {0,0};
        pair<int,int> left=dfs_greedy(root->left);
        pair<int,int> right=dfs_greedy(root->right);
        return {max(left.first,left.second)+max(right.first,right.second),root->val+left.first+right.first};
    }
    int rob(TreeNode* &root) 
    {
        pair<int,int> result=dfs_greedy(root);
        return max(result.first,result.second);
    }
};