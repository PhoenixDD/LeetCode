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
    bool same(TreeNode* s, TreeNode* t)
    {
        return !s&&!t||s&&t&&s->val==t->val&&same(s->left,t->left)&&same(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        return same(s,t)||s&&isSubtree(s->left,t)||s&&isSubtree(s->right,t);
    }
};