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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *latest=root,*popped=NULL;
        while(!s.empty()||latest)
        {
            if(latest)
                s.push(latest),latest=latest->left;
            else if(s.top()->right&&s.top()->right!=popped)
                latest=s.top()->right;
            else
            popped=s.top(),s.pop(),result.push_back(popped->val),latest=NULL;
        }
        return result;
    }
};