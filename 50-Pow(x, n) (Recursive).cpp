class Solution {
public:
    double Pw(double x, int n)
    {
        if(n==0)
            return 1;
        double temp=Pw(x,n/2);
        if(n&1)
            return x*temp*temp;
        else
            return temp*temp;
    }
    double myPow(double x, int n) 
    {
        if(n<0)
            return 1/Pw(x,-n);
        else
            return Pw(x,n);
    }
};