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
    vector<int> result;
    void helper(TreeNode* root,int level)
    {
        if(!root)
            return;
        if(level==result.size())
            result.push_back(root->val);
        helper(root->right,level+1);
        helper(root->left,level+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root)
    {
        helper(root,0);
        return result;
    }
};