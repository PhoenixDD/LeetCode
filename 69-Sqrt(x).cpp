//Neuton's Method
class Solution {
public:
    int mySqrt(int x)
    {
        if(x==1)
            return 1;
        long r=x/2;
        while(r*r>x)
            r=(r+x/r)/2;
        return r;
    }
};