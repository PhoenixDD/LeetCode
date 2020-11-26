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
    int MaxDepth=0;
    vector<int> result;
    void leftBoundary(TreeNode* root)
    {
        if(!root||!root->left&&!root->right)
            return;
        result.push_back(root->val);
        if(!root->left)
            return leftBoundary(root->right);
        leftBoundary(root->left);
    }
    void leaves(TreeNode* root)
    {
        if(!root)
            return;
        if(!root->left&&!root->right)
        {
            result.push_back(root->val);
            return;
        }
        leaves(root->left);
        leaves(root->right);
    }
    void rightBoundary(TreeNode* root)
    {
        if(!root||!root->left&&!root->right)
            return;
        if(!root->right)
            rightBoundary(root->left);
        else
            rightBoundary(root->right);
        result.push_back(root->val);
        
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) 
    {
        if(root)
        {
            result.push_back(root->val);
            leftBoundary(root->left);
            leaves(root->left);
            leaves(root->right);
            rightBoundary(root->right);
        }
        return result;
    }
};