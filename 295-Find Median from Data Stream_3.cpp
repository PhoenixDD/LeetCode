class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    void addNum(int num) 
    {
        left.push(num);
        right.push(left.top());                             //Balance eg, 1,2,3 (put to 3 right and get 2 put it to left)
        left.pop();
        if(left.size()<right.size())
            left.push(right.top()),right.pop();
    }
    double findMedian() 
    {
        return (left.size()+right.size())&1?left.top():((double)left.top()+right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */