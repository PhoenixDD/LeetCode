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
    stack<TreeNode*> pre,succ;
    double target;
    void get(TreeNode* root)
    {
        if(!root)
            return;
        if(root->val<=target)
        {
            pre.push(root);
            return get(root->right);
        }
        succ.push(root);
        return get(root->left);
    }
    int getPre()
    {
        int val=pre.top()->val;
        TreeNode* root=pre.top()->left;
        pre.pop();
        while(root)
            pre.push(root),root=root->right;
        return val;
    }
    int getSucc()
    {
        int val=succ.top()->val;
        TreeNode* root=succ.top()->right;
        succ.pop();
        while(root)
            succ.push(root),root=root->left;
        return val;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) 
    {
        this->target=target;
        get(root);
        vector<int> result;
        while(k--&&(!pre.empty()||!succ.empty()))
            if(pre.empty())
                result.push_back(getSucc());
            else if(succ.empty())
                result.push_back(getPre());
            else if((double)succ.top()->val-target<target-pre.top()->val)
                result.push_back(getSucc());
            else
                result.push_back(getPre());
        return result;
    }
};