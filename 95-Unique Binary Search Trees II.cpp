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
    vector<TreeNode*> gen(int start, int end)
    {
        vector<TreeNode*> res;
        if(start>end)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++)
        {

            vector<TreeNode*> left=gen(start,i-1);
            vector<TreeNode*> right=gen(i+1,end);
            for(TreeNode* &l:left)
            {
                for(TreeNode* &r:right)
                {
                    TreeNode* Node=new TreeNode(i);
                    Node->left=l;
                    Node->right=r;
                    res.push_back(Node);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n)
    {
        if(!n)
            return {};
        return gen(1,n);
    }
};