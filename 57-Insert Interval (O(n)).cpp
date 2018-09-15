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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        if(intervals.empty())
            return {newInterval};
        bool flag=false;
        for(int i=0;i<intervals.size();i++)
            if(newInterval.start<intervals[i].start)
            {
                flag=true;
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        if(!flag)
            intervals.push_back(newInterval);
        int put=0;
        for(int i=1;i<intervals.size();i++)
            if(intervals[put].end>=intervals[i].start)
                intervals[put].end=max(intervals[i].end,intervals[put].end);
            else
                intervals[++put]=intervals[i];
        intervals.resize(put+1);
        return intervals;
    }
};