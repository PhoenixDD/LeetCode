class Solution {
public:
    int numSquares(int n)
    {
        int size,count=0,i,x;
        unordered_set<int> visited;
        queue<int> q;
        q.push(n);
        while(!q.empty())
        {
            size=q.size();
            for(i=0;i<size;i++)
            {
                if(!q.front())
                    return count;
                for(x=sqrt(q.front());x>=1;x--)
                    if(visited.find(q.front()-x*x)==visited.end())
                        q.push(q.front()-x*x),visited.insert(q.front()-x*x);
                q.pop();
            }
            count++;
        }
        return 0;
    }
};