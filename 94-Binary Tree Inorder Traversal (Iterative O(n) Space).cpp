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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        TreeNode* last=root,*temp;
        vector<int> result;
        while(last||!s.empty())
        {
            if(last)
                s.push(last),last=last->left;
            else
            {
                result.push_back(s.top()->val);
                last=s.top()->right,s.pop();
            }
        }
        return result;
    }
};