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
    int max_d=0;
    void levelOrder(TreeNode* root,int depth)
    {
        if(root)
        {
            max_d=depth>max_d?depth:max_d;
            result[depth].push_back(root->val);
            levelOrder(root->left,depth+1);
            levelOrder(root->right,depth+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(!root)
            return {};
        result.resize(1000);
        levelOrder(root,0);
        result.resize(max_d+1);
        return result;
    }
};