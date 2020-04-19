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
    vector<ListNode*> splitListToParts(ListNode* root, int k)
    {
        int count=0,plusOneCount,listSize,emptyLists=0;
        ListNode* temp=root;
        vector<ListNode*> result;
        while(temp)
            count++,temp=temp->next;
        listSize=count/k;
        plusOneCount=count%k;
        if(count<k)
            emptyLists=k-plusOneCount;
        while(root)
        {
            count=0;
            temp=root;
            while(temp&&count<listSize-1)
                count++,temp=temp->next;
            if(plusOneCount&&listSize!=0&&temp)
                plusOneCount--,temp=temp->next;
            result.push_back(root);
            if(temp)
                root=temp->next;
            else
                root=NULL;
            if(temp)
                temp->next=NULL;
        }
        while(emptyLists--)
            result.push_back(NULL);
        return result;
    }
};