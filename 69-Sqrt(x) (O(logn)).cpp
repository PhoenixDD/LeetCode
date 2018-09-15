class Solution {
public:
    int mySqrt(int x) 
    {
        if(!x)
            return 0;
        int i=1,j=x,mid;
        while(i<=j)
        {
            mid=(i+j)>>1;
            if(x/mid>=mid&&x/(mid+1)<mid+1)
                return mid;
            if(x/mid>mid)
                i=mid+1;
            else
                j=mid-1;
        }
    }
};