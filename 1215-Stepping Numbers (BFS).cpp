class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) 
    {
       vector<int> result;
        int size;
        if(!low)
            result.push_back(0);
        queue<long> q;
        for(int i=1;i<=9;i++)
           q.push(i);
        while(!q.empty())
        {
            size=q.size();
            while(size--)
            {
                if(q.front()>=low&&q.front()<=high)
                    result.push_back(q.front());
                if(q.front()<high)
                {
                    if(q.front()%10>0)
                        q.push(q.front()*10+q.front()%10-1);
                    if(q.front()%10<9)
                        q.push(q.front()*10+q.front()%10+1);
                }
                q.pop();
            }
        }
        return result;
    }
};