//Binary Search
class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int start=1,end=num,mid;
        while(start<end)
        {
            mid=(start+end)>>1;
            if(mid<num/mid)
                start=mid+1;
            else
                end=mid;
        }
        return start*start==num;            
    }
};