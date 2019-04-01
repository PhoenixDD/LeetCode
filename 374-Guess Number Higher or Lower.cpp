// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) 
    {
        int start=1,end=n,res,mid;
        while(true)
        {
            mid=start+(end-start)/2;
            res=guess(mid);
            if(res==0)
                return mid;
            if(res==-1)
                end=mid-1;
            else
                start=mid+1;
        }
    }
};