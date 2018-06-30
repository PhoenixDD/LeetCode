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
    TreeNode* Prev=NULL;
    void flatten(TreeNode* root)
    {
        if(root)
        {
            flatten(root->right);
            flatten(root->left);
            root->right=Prev;
            root->left=NULL;
            Prev=root;
        }
    }
};