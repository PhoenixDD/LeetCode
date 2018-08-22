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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if(!root)
            return result;
        result.push_back(root->val);
        vector<int> result2=preorderTraversal(root->left);
        vector<int> result3=preorderTraversal(root->right);
        result.insert(result.end(),result2.begin(),result2.end());
        result.insert(result.end(),result3.begin(),result3.end());
        return result;
    }
};