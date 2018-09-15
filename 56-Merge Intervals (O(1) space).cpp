/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        if(intervals.size()<2)
            return intervals;
        int put=0,i=1;
        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){return a.start<b.start;});
        while(i<intervals.size())
            if(intervals[put].end>=intervals[i].start)
                intervals[put].end=max(intervals[put].end,intervals[i].end),i++;
            else
                intervals[++put]=intervals[i++];
        intervals.resize(put+1);
        return intervals;
        
    }
};