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
    int max_depth;
    int get_depth(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1+max(get_depth(root->left),get_depth(root->right));
    }
    void levelOrderBottom(TreeNode* root,int depth)
    {
        if(root)
        {
            result[max_depth-depth].push_back(root->val);
            levelOrderBottom(root->left,depth+1);
            levelOrderBottom(root->right,depth+1);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if(!root)
            return {};
        max_depth=get_depth(root);
        result.resize(max_depth);
        levelOrderBottom(root,1);
        return result;
    }
};