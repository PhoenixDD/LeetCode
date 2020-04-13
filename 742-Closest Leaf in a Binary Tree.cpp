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
    int k,result,Min=INT_MAX;
    void distBelow(TreeNode* root,int d)
    {
        if(!root)
            return;
        if(!root->left&&!root->right)
        {
            if(d<Min)
                result=root->val,Min=d;
            return;
        }
        distBelow(root->left,d+1),distBelow(root->right,d+1);
    }
    int dfs(TreeNode* root)
    {
        if(!root)
            return -1;
        if(root->val==k)
        {
            distBelow(root,0);
            return 0;
        }
        int l=dfs(root->left),r=dfs(root->right);
        if(l!=-1)
        {
            distBelow(root->right,l+1);
            return 1+l;
        }
        if(r!=-1)
        {
            distBelow(root->left,r+1);
            return 1+r;
        }
        return -1;
    }
    int findClosestLeaf(TreeNode* root, int k) 
    {
        this->k=k;
        dfs(root);
        return result;
    }
};
