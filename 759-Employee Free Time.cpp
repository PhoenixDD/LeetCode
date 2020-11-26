/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
typedef pair<int,int> ii;
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
    {
        auto cmp=[&schedule](auto &l,auto &r){return schedule[l.first][l.second].start>schedule[r.first][r.second].start;};
        priority_queue<ii,vector<ii>,decltype(cmp)> pq(cmp);
        for(int i=0;i<schedule.size();i++)
            pq.push({i,0});
        vector<Interval> result;
        int prevEnd=schedule[pq.top().first][pq.top().second].end;
        pair<int,int> temp;
        while(!pq.empty())
        {
            temp=pq.top();
            pq.pop();
            if(prevEnd<schedule[temp.first][temp.second].start)
                result.push_back(Interval(prevEnd,schedule[temp.first][temp.second].start)),prevEnd=schedule[temp.first][temp.second].end;
            else
                prevEnd=max(prevEnd,schedule[temp.first][temp.second].end);
            if(temp.second!=schedule[temp.first].size()-1)
                pq.push({temp.first,temp.second+1});
        }
        return result;
    }
};