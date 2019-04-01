class Solution {
public:
    vector<int> memo,next;
    int dfs(vector<int>& nums,int i,int &prev)
    {
        if(i==nums.size()||nums[i]%prev!=0)
            return 0;
        if(memo[i]!=1)
            return memo[i];
        int temp;
        for(int j=i+1;j<nums.size();j++)
        {
            temp=1+dfs(nums,j,nums[i]);
            if(memo[i]<temp)
                memo[i]=temp,next[i]=j;
        }
        return memo[i];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        vector<int> result;
        memo.resize(nums.size(),1);
        next.resize(nums.size(),-1);
        sort(nums.begin(),nums.end());
        int prev=1,Max=0,start,temp;
        for(int i=0;i<nums.size();i++)
            if((temp=dfs(nums,i,prev))>Max)
                start=i,Max=temp;
        while(start>=0)
            result.push_back(nums[start]),start=next[start];
        return result;
    }
};