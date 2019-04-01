class Solution {
public:
    int lastRemaining(int n) 
    {
        int size=n,begin=1,step=1;
        bool left=true;
        while(size!=1)
        {
            if(left||size%2==1)
                begin+=step;
            step*=2;                       //next number is eleminated each step thus the number to point begin to increase by 2.
            size/=2;
            left=!left;
        }
        return begin;
    }
};