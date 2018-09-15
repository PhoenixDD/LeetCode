/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(!a)
            return b;
        if(!b)
            return a;
        if(a->val<b->val)
        {
            a->next=merge(a->next,b);
            return a;
        }
        b->next=merge(a,b->next);
        return b;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists,int i,int j)
    {
        if(i<j)
        {
            int mid=(i+j)>>1;
            return merge(mergeKLists(lists,i,mid),mergeKLists(lists,mid+1,j));
        }
        return lists[i];
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.empty())
            return {};
        return mergeKLists(lists,0,lists.size()-1);
    }
};