class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        if(nums.size()<2)
            return 0;
        int Max=INT_MIN,Min=INT_MAX,index,prev,result=0;
        for(int &i:nums)
            Max=max(i,Max),Min=min(i,Min);
        double width=max((double)(Max-Min)/(nums.size()-1),1.0);
        vector<int> Max_bucket(nums.size(),INT_MIN);
        vector<int> Min_bucket(nums.size(),INT_MAX);
        for(int &i:nums)
        {
            index=(i-Min)/width;
            Max_bucket[index]=max(i,Max_bucket[index]),Min_bucket[index]=min(i,Min_bucket[index]);
        }
        prev=Max_bucket[0];
        for(int i=1;i<nums.size();i++)
            if(Min_bucket[i]!=INT_MAX)
                result=max(result,Min_bucket[i]-prev),prev=Max_bucket[i];
        return result;
    }
};