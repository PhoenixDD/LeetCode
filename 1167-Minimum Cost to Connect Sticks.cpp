class Solution {
public:
    int connectSticks(vector<int>& sticks) 
    {
        int result=0,first,second;
        priority_queue<int,vector<int>,greater<int>> pq(sticks.begin(),sticks.end());
        while(pq.size()>1)
        {
            first=pq.top(),pq.pop();
            second=pq.top(),pq.pop();
            result+=first+second;
            pq.push(first+second);
        }
        return result;
    }
};