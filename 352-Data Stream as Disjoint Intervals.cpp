/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    struct cmp
    {
        bool operator()(const Interval &n1,const Interval &n2) const
        {return n1.start<n2.start;}
    };
    set<Interval,cmp> s;
    SummaryRanges() 
    {
    }
    void addNum(int val) 
    {
        Interval temp(val,val);
        it=s.lower_bound(temp);
        if(!s.empty())
            it--;
        if(it!=s.end()&&it->start<temp.start)
        {
            if(val<=it->end)
                return;
            else if(val==it->end+1)
                temp.start=it->start,s.erase(it);
        }
        it=s.upper_bound(temp);
        if(it!=s.end())
            if(val==it->start-1)
                temp.end=it->end,s.erase(it);
        s.insert(temp);
    }
    
    vector<Interval> getIntervals() 
    {
        vector<Interval> result(s.begin(),s.end());
        return result;
    }
    private:
    set<Interval,cmp>::const_iterator it;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */