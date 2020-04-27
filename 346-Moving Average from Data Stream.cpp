class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) 
    {
        this->size=size;
    }
    
    double next(int val)
    {
        if(dq.size()==size)
            sum-=dq.front(),dq.pop_front();
        dq.push_back(val);
        sum+=val;
        return (double)sum/dq.size();
    }
    private:
    int sum=0,size;
    deque<int> dq;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */