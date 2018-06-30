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
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(!root)
            return false;/**
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
    vector<vector<int>> result;
    vector<int> temp;
    void helper(TreeNode* root, int sum)
    {
        /*for(auto &i:temp)
            cout<<i<<" ";
        cout<<endl;*/
        if(!root)
            return;
        temp.push_back(root->val);
        if(root->val==sum&&!root->right&&!root->left)
        {
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        helper(root->left,sum-root->val);
        helper(root->right,sum-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        temp.reserve(1000);
        result.reserve(1000);
        helper(root,sum);
        return result;
    }
};