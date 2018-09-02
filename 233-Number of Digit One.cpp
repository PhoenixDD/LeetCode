class Solution {
public:
    int countDigitOne(long n) 
    {
        if(n<1)
            return 0;
        if(n<10)
            return 1;
        int msd=n,d=1;
        while(msd>=10)
            msd/=10,d*=10;
        if(msd==1)
            return n-d+1+countDigitOne(d-1)+countDigitOne(n%d);
        else
            return d+msd*countDigitOne(d-1)+countDigitOne(n%d);
    }
};