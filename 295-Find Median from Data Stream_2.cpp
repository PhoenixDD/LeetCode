class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) 
    {
        sorted.insert(num);
        if(sorted.size()==1)
            mid_1=sorted.begin();
        else if(num<*mid_1)
        {
            if(sorted.size()%2==0)
                mid_1--;
        }
        else if(sorted.size()&1)
            mid_1++;
    }
    
    double findMedian() 
    {
        return sorted.size()&1?*mid_1:((double)*(++(mid_2=mid_1))+*mid_1)/2;
    }
    private:
    multiset<int> sorted;
    multiset<int>::iterator mid_1,mid_2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */