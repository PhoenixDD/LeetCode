class Solution {
public:
    bool canMeasureWater(int x, int y, int z) 
    {
        if(x==z||y==z)
            return true;
        queue<int> q;
        unordered_set<int> visited;
        visited.insert(0);
        q.push(0);
        while(!q.empty())
        {
            if(q.front()==z)
                return true;
            if(q.front()+x<=x+y&&visited.insert(q.front()+x).second)
                q.push(q.front()+x);
            if(q.front()+y<=x+y&&visited.insert(q.front()+y).second)
                q.push(q.front()+y);
            if(q.front()-x>=0&&visited.insert(q.front()-x).second)
                q.push(q.front()-x);
            if(q.front()-y>=0&&visited.insert(q.front()-y).second)
                q.push(q.front()-y);
            q.pop();
        }
        return false;
    }
};