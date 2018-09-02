// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        long i=1,j=n,mid;
        while(i<j)
        {
            mid=(i+j)/2;
            if(isBadVersion(mid))
                j=mid;
            else if(!isBadVersion(mid))
                i=mid+1;
        }
        return j;
    }
};