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
    int result=1;
    int dfs(TreeNode* root,int &Min,int &Max)
    {
        if(!root)
            return 0;
        int lMax=INT_MIN,lMin=INT_MAX,rMax=INT_MIN,rMin=INT_MAX,l=dfs(root->left,lMin,lMax),r=dfs(root->right,rMin,rMax);
        Min=min(root->val,min(lMin,rMin)),Max=max(root->val,max(lMax,rMax));
        if(l!=-1&&r!=-1&&root->val>lMax&&root->val<rMin)
        {
            result=max(result,1+l+r);
            return 1+l+r;
        }
        return -1;
    }
    int largestBSTSubtree(TreeNode* root)
    {
        if(!root)
            return 0;
        int Max,Min;
        dfs(root,Min,Max);
        return result;
    }
};