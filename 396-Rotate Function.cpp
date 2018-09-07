class Solution {
public:
    int maxRotateFunction(vector<int>& A) 
    {
        int sum=0,cur=0;
        for(int i=0;i<A.size();i++)
            sum+=A[i],cur+=i*A[i];
        int Max=cur;
        for(int i=1;i<=A.size();i++)
            Max=max(Max,cur=cur-sum+A.size()*A[i-1]);
        return Max;
    }
};