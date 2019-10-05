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
    bool search(TreeNode* root,int target)
    {
        if(!root)
            return false;
        if(root->val==target)
            return true;
        return target<root->val?search(root->left,target):search(root->right,target);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) 
    {
        if(!root1||!root2)
            return false;
        if(search(root2,target-root1->val))
            return true;
        if(root2->val<target-root1->val)
            return twoSumBSTs(root1->left,root2->right,target)||twoSumBSTs(root1->right,root2,target);
        return twoSumBSTs(root1->left,root2,target)||twoSumBSTs(root1->right,root2->left,target);
    }
};