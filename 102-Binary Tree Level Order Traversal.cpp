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
    vector<vector<int>> result;
    void levelOrder(TreeNode* root,int d)
    {
        if(!root)
            return;
        if(result.size()==d)
            result.push_back({root->val});
        else
            result[d].push_back(root->val);
        levelOrder(root->left,d+1);
        levelOrder(root->right,d+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        levelOrder(root,0);
        return result;
    }
};