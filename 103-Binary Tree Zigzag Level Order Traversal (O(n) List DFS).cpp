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
    vector<vector<int>> result;
    vector<list<int>> result2;
    int max=0;
    void zigzagLevelOrder(TreeNode* root,int depth)
    {
        if(root)
        {
            max=std::max(max,depth);
            if(depth%2==0)
                result[depth].push_back(root->val);
            else
                result2[depth].push_front(root->val);
            zigzagLevelOrder(root->left,depth+1);
            zigzagLevelOrder(root->right,depth+1);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if(!root)
            return {};
        result.resize(1000);
        result2.resize(1000);
        zigzagLevelOrder(root,0);
        result.resize(max+1);
        for(int i=0;i<=max;i++)
            if(i%2)
                result[i]=vector<int>(result2[i].begin(),result2[i].end());
        return result;
    }
};