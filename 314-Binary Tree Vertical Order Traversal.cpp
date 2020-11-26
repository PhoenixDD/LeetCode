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
    int buffer;
    int getMin(TreeNode* root)
    {
        if(!root)
            return 0;
        return min(1+getMin(root->right),-1+getMin(root->left));
    }
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<vector<int>> result;
        buffer=getMin(root);
        buffer=abs(buffer)-1;
        result.resize(buffer);
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
            for(int size=q.size();size;size--,q.pop())
            {
                if(q.front().second+buffer==result.size())
                    result.push_back({q.front().first->val});
                else
                    result[q.front().second+buffer].push_back(q.front().first->val);
                if(q.front().first->left)
                    q.push({q.front().first->left,q.front().second-1});
                if(q.front().first->right)
                    q.push({q.front().first->right,q.front().second+1});
            }
        return result;
    }
};