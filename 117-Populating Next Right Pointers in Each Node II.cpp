/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        if(!root)
            return;
        TreeLinkNode* next;
        if(root->left)
        {
            if(root->right)
                root->left->next=root->right;
            else
            {
                next=root->next;
                while(next)
                {
                    if(next->left)
                    {
                        root->left->next=next->left;
                        break;
                    }
                    else if(next->right)
                    {
                        root->left->next=next->right;
                        break;
                    }
                    next=next->next;
                }
            }
        }
        if(root->right)
        {
            next=root->next;
            while(next)
            {
                if(next->left)
                {
                    root->right->next=next->left;
                    break;
                }
                else if(next->right)
                {
                    root->right->next=next->right;
                    break;
                }
                next=next->next;
            }
        }
        connect(root->right);
        connect(root->left);
    }
};