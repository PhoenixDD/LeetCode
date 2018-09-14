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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* Dummy=new ListNode(-1),*temp=Dummy;
        bool carry=false;
        while(l1||l2||carry)
        {
            temp->next=new ListNode(carry+(l1&&l2?l1->val+l2->val:l1?l1->val:l2?l2->val:0));
            temp=temp->next;
            carry=temp->val/10;
            temp->val%=10;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        return Dummy->next;
    }
};