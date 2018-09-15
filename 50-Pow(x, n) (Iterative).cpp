class Solution {
public:
    double myPow(double x, int n)
    {        
        if(n==0)
            return 1;
        else if(n==1)
            return x;
        bool sign=false;
        double res=1;
        if(n<0)
            sign=true;
        if(n==INT_MIN&&x!=1&&x!=-1)
            return 0;
        else if(n==INT_MIN)
            return 1;
        n=abs(n);
        while(n>0)
        {
            if(n&1)
                res*=x;
            n=n>>1;
            x*=x;
        }
        if(sign)
            return 1/res;
        else
            return res;
    }
};