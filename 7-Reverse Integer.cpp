class Solution {
public:
    
    int reverse(int x) 
    {
        if(x>INT_MAX||x<INT_MIN||x==0)
            return 0;
        int y=x<0?-x:x;
        bool sign=x<0?false:true;
        x=0;
        while(y>0)
        {
            if((x>INT_MAX/10&&sign)||x*10+(y%10)<x||(x>(long)-1*INT_MIN/10&&!sign))
                return 0;
            x*=10;
            x+=y%10;
            y/=10;
        }
        if(sign)
            return x;
        else
            return -x;
    }
};