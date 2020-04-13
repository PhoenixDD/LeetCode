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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* &p) 
    {
        if(!root)
            return NULL;
        if(root->val>p->val)
        {
            TreeNode* left=inorderSuccessor(root->left,p);
            return left&&left->val<root->val?left:root;
        }
        else
        {
            TreeNode* right=inorderSuccessor(root->right,p);
            return right&&right->val>p->val?right:NULL;
        }
    }
};