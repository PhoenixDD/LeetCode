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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<vector<int>> result;
        int depth=0;
        vector<TreeNode*> q;
        q.push_back(root);
        while(!q.empty())
        {
            vector<TreeNode*> temp;
            if(depth&1)
            {
                for(int i=q.size()-1;i>=0;i--)
                {
                    if(result.size()==depth)
                        result.push_back({q[i]->val});
                    else
                        result[depth].push_back(q[i]->val);
                }
            }
            else
            {
                for(int i=0;i<q.size();i++)
                {
                    if(result.size()==depth)
                        result.push_back({q[i]->val});
                    else
                        result[depth].push_back(q[i]->val);
                }
            }
            for(int i=0;i<q.size();i++)
            {
                if(q[i]->left)
                    temp.push_back(q[i]->left);
                if(q[i]->right)
                    temp.push_back(q[i]->right);
            }
            q.swap(temp);
            depth++;
        }
        return result;
    }
};