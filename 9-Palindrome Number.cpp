class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;
        int x1=x;
        long long y=0;
        while(x>0)
        {
            y*=10;
            y+=x%10;
            x/=10;
        }
        if(x1==y)
            return true;
        else 
            return false;
    }
};