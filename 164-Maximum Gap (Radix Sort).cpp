class Solution {
public:
    void countSort(vector<int> &nums,int d)
    {
        vector<int> copy(nums.size()),count(10,0);
        for(int &i:nums)
            count[(i/d)%10]++;
        for(int i=1;i<10;i++)
            count[i]+=count[i-1];
        for(int i=nums.size()-1;i>=0;i--)
            copy[count[(nums[i]/d)%10]-1]=nums[i],count[(nums[i]/d)%10]--;
        nums.swap(copy);           
    }
    void radix(vector<int> &nums)
    {
        int Max=0;
        for(int &i:nums)
            Max=max(Max,i);
        for(int i=1;Max/i;i*=10)
            countSort(nums,i);
    }
    int maximumGap(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        radix(nums);
        int Max=0;
        for(int i=1;i<nums.size();i++)
            Max=max(nums[i]-nums[i-1],Max);
        return Max;
    }
};