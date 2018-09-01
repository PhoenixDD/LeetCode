class Solution {
public:
    int next(int n)
    {
        int result=0;
        while(n)
            result+=(n%10)*(n%10),n/=10;
        return result;
    }
    bool isHappy(int n) 
    {
        int slow=n,fast=n;
        do
        {
            slow=next(slow);
            fast=next(next(fast));
        }while(slow!=fast&&fast!=1);
        return fast==1;
    }
};