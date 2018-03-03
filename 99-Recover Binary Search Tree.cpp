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
    TreeNode *prev=NULL,*swap1=NULL,*swap2=NULL;
    void swapp(TreeNode* root)
    {
        if(!root)
            return;
        swapp(root->left);
        if(prev&&prev->val>=root->val)
        {
            if(!swap1)
                swap1=prev;
            swap2=root;
        }
        prev=root;
        swapp(root->right);
    }
    void recoverTree(TreeNode* root)
    {
        swapp(root);
        swap1->val+=swap2->val;
        swap2->val=swap1->val-swap2->val;
        swap1->val-=swap2->val;
    }
};