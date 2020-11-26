//We need to start backwards for this approach, this way we can use sliding window to set the next selection of i.
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) 
    {
        if(A.front()==-1||A.back()==-1)
            return {};
        deque<int> dq;
        dq.push_back(A.size()-1);
        vector<int> result,next(A.size(),-1),cost(A.size(),-1);
        for(int i=A.size()-2;i>=0;i--)
            if(A[i]!=-1)
            {
                while(!dq.empty()&&dq.back()>i+B)
                    dq.pop_back();
                if(dq.empty())
                        return {};
                next[i]=dq.back();
                cost[i]=cost[dq.back()]+A[i];
                if(A[i]==0)
                    dq.clear();
                while(!dq.empty()&&cost[i]<=cost[dq.front()])
                    dq.pop_front();
                dq.push_front(i);
            }
        for(int start=0;start!=-1;)
            result.push_back(start+1),start=next[start];
        return result;
    }
};