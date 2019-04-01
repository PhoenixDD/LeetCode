//Reservoir Sampling for when we don't know 'n'
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* Head;
    Solution(ListNode* head) 
    {
        Head=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int n=1,result;
        ListNode* node=Head;
        while(node)
        {
            if(rand()%n==0)
                result=node->val;
            node=node->next;
            n++;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */