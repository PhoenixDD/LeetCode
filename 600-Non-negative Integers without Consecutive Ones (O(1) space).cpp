class Solution {
public:
    int findIntegers(int num) 
    {
        num++;
        int res=0,a=1,b=2,c;
        while(num)
        {
            if((num&3)==3)
                res=0;
            res+=a*(num&1);
            num>>=1;
            c=a+b;
            a=b;
            b=c;
        }
        return res;
    }
};