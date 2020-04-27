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
    pair<int,int> preOrder(TreeNode* root)
    {
        if(!root)
            return {0,0};
        int inc=1,dec=1;
        if(root->left)
        {
            pair<int,int> l=preOrder(root->left);
            if(root->val==root->left->val+1)
                dec=l.first+1;
            else if(root->val==root->left->val-1)
                inc=l.second+1;
        }
        if(root->right)
        {
            pair<int,int> r=preOrder(root->right);
            if(root->val==root->right->val+1)
                dec=max(dec,r.first+1);
            else if(root->val==root->right->val-1)
                inc=max(inc,r.second+1);
        }
        result=max(result,inc+dec-1);
        return {dec,inc};
    }
    int longestConsecutive(TreeNode* root)
    {
        preOrder(root);
        return result;
    }
};