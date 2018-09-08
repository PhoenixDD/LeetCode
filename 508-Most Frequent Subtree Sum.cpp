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
    unordered_map<int,int> map;
    int Max=0;
    int traverse(TreeNode* root)
    {
        if(!root)
            return 0;
        int val=root->val+traverse(root->left)+traverse(root->right);
        Max=max(Max,++map[val]);
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        traverse(root);
        vector<int> result;
        for(auto it=map.begin();it!=map.end();it++)
            if(it->second==Max)
                result.push_back(it->first);
        return result;
    }
};