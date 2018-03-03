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
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        result.reserve(10000);
        inorder(root);
        return result;
    }
};