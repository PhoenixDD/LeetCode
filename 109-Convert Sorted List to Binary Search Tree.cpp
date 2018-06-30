/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    vector<ListNode*> all_indices;
    TreeNode* sortedListToBST(int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* Node=new TreeNode(all_indices[mid]->val);
        if(start==end)
            return Node;
        Node->left=sortedListToBST(start,mid-1);
        Node->right=sortedListToBST(mid+1,end);
        return Node;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        all_indices.reserve(1000);
        ListNode* temp=head;
        while(temp)
        {
            all_indices.push_back(temp);
            temp=temp->next;
        }
        return sortedListToBST(0,all_indices.size()-1);
    }
};