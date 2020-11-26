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
    double target,Min=DBL_MAX;
    int result;
    void findClosest(TreeNode* root)
    {
        if(!root)
            return;
        if(abs(target-root->val)<Min)
            Min=abs(target-root->val),result=root->val;
        root->val<target?findClosest(root->right):findClosest(root->left);
    }
    int closestValue(TreeNode* root, double target) 
    {
        this->target=target;
        findClosest(root);
        return result;
    }
};