class MaxStack {
public:
    
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x)
    {
        l.push_back(x);
        mp[x].push_front(--l.end());
    }
    
    int pop() 
    {
        mp[l.back()].pop_front();
        if(mp[l.back()].empty())
            mp.erase(l.back());
        result=l.back();
        l.pop_back();
        return result;
    }
    
    int top() 
    {
        return l.back();
    }
    
    int peekMax()
    {
        return mp.begin()->first;
    }
    
    int popMax() 
    {
        result=mp.begin()->first;
        l.erase(mp.begin()->second.front());
        mp.begin()->second.pop_front();
        if(mp.begin()->second.empty())
            mp.erase(mp.begin());
        return result;
    }
    
    private:
    int result;
    map<int,list<list<int>::iterator>,greater<int>> mp;
    list<int> l;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */