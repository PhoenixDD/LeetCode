class Solution {
public:
    string smallestGoodBase(string n) 
    {
        unsigned long long sum,l,r,mid,x,N=stoll(n);
        for(int i=log2(N)+1;i>2;i--)
        {
            l=2,r=pow((double)N,(double)1/(i-1))+1;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                sum=1;
                x=mid;
                for(int p=1;p<i;p++)
                    sum+=x,x*=mid;
                if(sum>N)
                    r=mid-1;
                else if(sum<N)
                    l=mid+1;
                else
                    return to_string(mid);
            }
        }
        return to_string(N-1);
    }
};