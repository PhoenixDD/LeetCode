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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty())
            return {newInterval};
        vector<Interval> result;
        result.reserve(intervals.size());
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.start<b.start;});
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start>result.back().end)
                result.push_back(intervals[i]);
            else
                result.back().end=max(result.back().end,intervals[i].end);
        }
        return result;
        
    }
};