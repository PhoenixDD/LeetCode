class Solution {
public:
    int M;
    bool valid(vector<int>& nums,int mid)
    {
        int sum=0;
        int count=1;
        for(int &num:nums)
        {
            sum+=num;
            if(sum>mid)
            {
                sum=num;
                count++;
                if(count>M)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) 
    {
        M=m;
        int j=0,i=-1,mid;
        for(int &num:nums)
            j+=num,i=max(i,num);
        if(m==1)
            return j;
        while(i<=j)
        {
            mid=(i+j)>>1;
            if(valid(nums,mid))
                j=mid-1;
            else
                i=mid+1;
        }
        return i;
    }
};