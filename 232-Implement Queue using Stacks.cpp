class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        i_s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        peek();
        t=o_s.top();
        o_s.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() 
    {
        if(o_s.empty())
            while(!i_s.empty())
                o_s.push(i_s.top()),i_s.pop();
        return o_s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return i_s.empty()&&o_s.empty();
    }
    private:
    stack<int> i_s,o_s;
    int t;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */