class Solution {
public:
    int next(int &n,long start)
    {
        long end=start+1;
        int next=0;
        while(start<=n)
        {
            next+=(n+1<end?n+1:end)-start;
            start*=10;
            end*=10;
        }
        return next;
    }
    int findKthNumber(int n, int k) 
    {
        int start=1,nums;
        k--;
        while(k>0)
        {
            nums=next(n,start);
            if(nums<=k)
                k-=nums,start++;
            else
                start*=10,k--;
        }
        return start;
    }
};