class Solution {
public:
    int result=0,l,u;
    void countSmaller(vector<long>& nums,int start,int end)
    {
        if(end-start>1)
        {
            int mid=(start+end)/2;
            countSmaller(nums,start,mid);
            countSmaller(nums,mid,end);
            int m=mid,n=mid;
            for(int i=start;i<mid;i++)
            {
                while(m<end&&nums[m]-nums[i]<l)m++;
                while(n<end&&nums[n]-nums[i]<=u)n++;
                result+=n-m;
            }
            inplace_merge(nums.begin()+start,nums.begin()+mid,nums.begin()+end);
        }
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        vector<long> sums(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
            sums[i+1]=sums[i]+nums[i];
        l=lower,u=upper;
        countSmaller(sums,0,sums.size());
        return result;
    }
};