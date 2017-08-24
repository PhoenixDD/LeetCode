class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if(dividend==0)
            return 0;
        else if(divisor==1)
            return dividend;
        else if(divisor==-1&&dividend>0)
            return -dividend;
        else if(divisor==-1&&dividend<0)
        {
            if(dividend==INT_MIN)
                return INT_MAX;
            else 
                return -dividend;
        }
        else if(dividend==divisor)
            return 1;
        else if(dividend==-divisor)
            return -1;
        int divid=dividend,divi=divisor;
        dividend=abs(dividend),divisor=abs(divisor);
        long long remain=abs((long long)dividend);
        int quotient=0;
        for(int i=31;i>0&&remain>0;i--)
            if(remain>=(long long)divisor<<i)
                remain-=(long long)divisor<<i,quotient+=1<<i;
        while(remain>=divisor)
            remain-=divisor,quotient++;
        if((divid<0&&divi<0)||(divid>0&&divi>0))
            return quotient;
        else 
            return -quotient;
    }
};