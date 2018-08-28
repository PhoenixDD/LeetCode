class MinStack {
public:
    /** initialize your data structure here. */
    struct Node
    {
        int val;
        Node *next,*min;
        Node(int v) : val(v){};
    }*first;
    MinStack()
    {
        first=NULL;
    }
    void push(int x)
    {
        if(first==NULL)
        {
            first=new Node(x);
            first->next=NULL;
            first->min=first;
        }
        else
        {
            Node *temp=new Node(x);
            if(first->min->val>=x)
                temp->min=temp;
            else
                temp->min=first->min;
            temp->next=first;
            first=temp;
        }
    }
    void pop()
    {
        if(first)
        {
            Node *temp=first;
            first=first->next;
            delete temp;
        }
    }
    
    int top()
    {
        if(first)
            return first->val;
    }
    
    int getMin()
    {
        if(first)
            return first->min->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */