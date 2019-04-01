//Newton's Method
class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num==1)
            return true;
        long r=num/2;
        while(r>num/r)
            r=(r+num/r)/2;
        return r*r==num;       
    }
};