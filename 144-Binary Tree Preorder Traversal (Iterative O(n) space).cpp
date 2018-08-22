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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if(!root)
            return result;
        result.push_back(root->val);
        vector<int> result2=preorderTraversal(root->left);
        vector<int> result3=preorderTraversal(root->right);
        result.insert/**
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *node;
        s.push(root);
        while(!s.empty())
        {
            node=s.top();s.pop();
            if(node)
            {
                result.push_back(node->val);
                node->right?s.push(node->right):void();
                node->left?s.push(node->left):void();
            }
        }
        return result;
        
    }
};