class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> s;
        int i=0,temp,Max=0;
        while(i<heights.size())
            if(s.empty()||heights[i]>heights[s.top()])
                s.push(i++);
            else
            {
                temp=heights[s.top()];
                s.pop();
                Max=max(Max,temp*(s.empty()?i:i-s.top()-1));
            }
        while(!s.empty())
        {
            temp=heights[s.top()];
            s.pop();
            Max=max(Max,temp*(s.empty()?i:i-s.top()-1));
        }
        return Max;
    }
};