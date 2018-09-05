class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {       
        median=0;
    }

    
    void addNum(int num) 
    {
        if(left.size()==right.size())
        {
            if(num<median)
                left.push(num),median=left.top();
            else
                right.push(num),median=right.top();
        }
        else if(left.size()>right.size())
        {
            if(num>median)
                right.push(num);
            else
                right.push(left.top()),left.pop(),left.push(num);
            median=(double)(left.top()+right.top())/2;
        }
        else
        {
            if(num>median)
                left.push(right.top()),right.pop(),right.push(num);
            else
                left.push(num);
            median=(double)(left.top()+right.top())/2;
        }
    }
    
    double findMedian() 
    {
        return median;
    }
    private:
    priority_queue<int,vector<int>,greater<int>> right;
    priority_queue<int> left;
    double median;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */