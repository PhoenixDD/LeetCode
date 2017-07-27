class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        bool carry=false;
        ListNode *result=new ListNode(-1),*temp=result;
        while(l1&&l2)
        {
            if(temp->val==-1)
                temp->val=(l1->val+l2->val+carry)%10;
            else
            {
                temp->next=new ListNode((l1->val+l2->val+carry)%10);
                temp=temp->next;
            }
            if(l1->val+l2->val+carry>=10)
                carry=true;
            else
                carry=false;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            if(temp->val==-1)
                temp->val=(l1->val+carry)%10;
            else
            {
                temp->next=new ListNode((l1->val+carry)%10);
                temp=temp->next;
            }    
            if(l1->val+carry>=10)
                carry=true;
            else
                carry=false;
            l1=l1->next;
        }
        while(l2)
        {
            if(temp->val==-1)
                temp->val=(l2->val+carry)%10;
            else
            {
                temp->next=new ListNode((l2->val+carry)%10);
                temp=temp->next;
            }
            if(l2->val+carry>=10)
                carry=true;
            else
                carry=false;
            l2=l2->next;
        }
        if(carry)
            temp->next=new ListNode(1);
        return result;
    }
};