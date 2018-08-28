/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root)
    {
       for(;root;s.push(root),root=root->left);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        temp=s.top();
        s.pop();
        root=temp->right;
        for(;root;s.push(root),root=root->left);
        return temp->val;
    }
    private:
    stack<TreeNode*> s;
    TreeNode* temp,*root;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */