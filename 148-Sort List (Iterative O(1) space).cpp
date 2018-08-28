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
    ListNode* merge(ListNode *left,ListNode *right,ListNode *head)
    {
        while(left&&right)
        {
            if(left->val<right->val)
                head->next=left,left=left->next;
            else
                head->next=right,right=right->next;
            head=head->next;
        }
        if(left)
            head->next=left;
        else if(right)
            head->next=right;
        while(head->next)
            head=head->next;
        return head;       
    }
    ListNode* sortList(ListNode* head)
    {
        if(!head||!head->next)
            return head;
        int length=0,count;
        ListNode *temp=head,*left,*right,*next,*back;
        while(temp)
            temp=temp->next,length++;
        for(int step=1;step<length;step<<=1)
        {
            ListNode *dummy=new ListNode(INT_MIN);
            back=dummy;
            temp=head;
            while(temp)
            {
                left=temp;
                right=NULL;
                count=1;
                while(count<step&&temp)
                    temp=temp->next,count++;
                if(temp)
                {
                    right=temp->next;
                    temp->next=NULL;
                    temp=right;
                    count=1;
                    if(right)
                    {
                        while(count<step&&temp)
                            temp=temp->next,count++;
                        if(temp)
                        {
                            next=temp->next;
                            temp->next=NULL;
                            temp=next;
                        }
                    }
                }
                back=merge(left,right,back);
            }
            head=dummy->next;
        }
        return head;
        
    }
};