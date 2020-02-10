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
    void dfs(TreeNode* root,int grandParent,int parent)
    {
        if(!root)
            return;
        if(grandParent%2==0)
            result+=root->val;
        dfs(root->left,parent,root->val);
        dfs(root->right,parent,root->val);
    }
    int sumEvenGrandparent(TreeNode* root) 
    {
        dfs(root,-1,-1);
        return result;
    }
};