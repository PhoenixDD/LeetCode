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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* list2=NULL,*List=NULL;
        if(l1&&l2)
        {
            List=new ListNode((l1->val<l2->val?l1->val:l2->val));
            list2=List;
            l1->val<l2->val?l1=l1->next:l2=l2->next;
        }
        else if(l1)
        {
            List=new ListNode(l1->val);
            list2=List;
            l1=l1->next;
        }
        else if(l2)
        {
            List=new ListNode(l2->val);
            list2=List;
            l2=l2->next;
        }
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                List->next=new ListNode(l1->val);
                List=List->next;
                l1=l1->next;
            }
            else
            {
                List->next=new ListNode(l2->val);
                List=List->next;
                l2=l2->next;
            }
        }
        while(l1)
        {
            List->next=new ListNode(l1->val);
            List=List->next;
            l1=l1->next;
        }
        while(l2)
        {
            List->next=new ListNode(l2->val);
            List=List->next;
            l2=l2->next;
        }
        return list2;
    }
};