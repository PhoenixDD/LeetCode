class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        bool sign=false;
        if(dividend==0||divisor==1)
            return dividend;
        if(dividend<0&&divisor>0||dividend>0&&divisor<0)
            sign=true;
        if(dividend==INT_MIN&&divisor==-1)
            return INT_MAX;
        long divi=abs((long)dividend),div=abs((long)divisor);
        int result=0;
        for(int i=31;i>1;i--)
            if(divi>(long)div<<i)
                divi-=(long)div<<i,result+=1<<i;
        while(divi>=div)
            divi-=div,result++;
        return sign?-result:result;
    }
};