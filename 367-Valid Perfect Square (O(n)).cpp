//Perfect square=1+3+5+7.....
class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int i=-1;
        while(num>0)
            num-=i+=2;
        return num==0;            
    }
};