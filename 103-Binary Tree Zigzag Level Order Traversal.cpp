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
    void zigzagLevelOrder(TreeNode* root,int depth)
    {
        if(root)
        {
            max_d=depth>max_d?depth:max_d;
            if(depth&1)
                result[depth].insert(result[depth].begin(),root->val);
            else
                result[depth].push_back(root->val);
            zigzagLevelOrder(root->left,depth+1);
            zigzagLevelOrder(root->right,depth+1);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if(!root)
            return {};
        result.resize(1000);
        zigzagLevelOrder(root,0);
        result.resize(max_d+1);
        return result;
    }
};