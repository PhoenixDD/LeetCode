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
    vector<string> result;
    string temp="";
    void helper(TreeNode* &root)
    {
        if(!root->left&&!root->right)
        {
            int i=temp.length();
            temp+=to_string(root->val);
            result.push_back(temp);
            temp.erase(temp.begin()+i,temp.end());
            return;
        }
        int i=temp.length();
        temp+=to_string(root->val)+"->";
        if(root->left)
            helper(root->left);
        if(root->right)
            helper(root->right);
        temp.erase(temp.begin()+i,temp.end());
    }
    vector<string> binaryTreePaths(TreeNode* &root)
    {
        if(!root)
            return {};
        temp.reserve(1000);
        result.reserve(100);
        helper(root);
        return result;
    }
};