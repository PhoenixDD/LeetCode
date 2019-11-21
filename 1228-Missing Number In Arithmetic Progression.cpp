class Solution {
public:
    int missingNumber(vector<int>& arr) 
    {
        int d=(arr.back()-arr.front())/(int)arr.size();
        int i=0,j=arr.size()-1,mid;
        while(i<j)
        {
            mid=(i+j)>>1;
            if(arr[mid]==arr.front()+mid*d)                      //All numbers upto mid have no missing number.
                i=mid+1;
            else
                j=mid;
        }
        return arr.front()+d*i;
    }
};