class Solution {
public:
    int getnext(int n)
    {
        return !n?0:(n%10)*(n%10)+getnext(n/10);
    }
    bool isHappy(int n)
    {
        int slow=n,fast=n;
        do
        {
            slow=getnext(slow);
            fast=getnext(fast);
            fast=getnext(fast);
            if(fast==1)
                return true;
        }while(slow!=fast);
        return false;
    }
};