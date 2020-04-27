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
    int result=0;
    bool preOrder(TreeNode* root)
    {
        if(!root)
            return true;
        bool left=preOrder(root->left),ret=preOrder(root->right)&&left;
        if(ret)
        {
            if(root->left&&root->val!=root->left->val)
                return false;
            if(root->right&&root->val!=root->right->val)
                return false;
            result++;
        }
        return ret;
            
    }
    int countUnivalSubtrees(TreeNode* root) 
    {
        preOrder(root);
        return result;
    }
};