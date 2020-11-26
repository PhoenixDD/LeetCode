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
    vector<vector<int>> result;
    int dfs(TreeNode* root)
    {
        if(!root)
            return -1;
        int h=1+max(dfs(root->left),dfs(root->right));
        if(result.size()==h)
            result.push_back({root->val});
        else
            result[h].push_back(root->val);
        return h;      
    }
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        dfs(root);
        return result;
    }
};