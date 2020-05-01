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
    vector<TreeNode*> splitBST(TreeNode* root, int V) 
    {
        if(!root)
            return {NULL,NULL};
        if(root->val<=V)
        {
            vector<TreeNode*> result(splitBST(root->right,V));
            root->right=result.front();
            result.front()=root;
            return result;
        }
        else
        {
            vector<TreeNode*> result(splitBST(root->left,V));
            root->left=result.back();
            result.back()=root;
            return result;
        }
    }
};