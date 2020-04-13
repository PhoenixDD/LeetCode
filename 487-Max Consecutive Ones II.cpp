class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int start=0,result=0,flipped=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(!nums[i])
            {
                if(flipped!=-1)
                    start=flipped+1,flipped=i;
                else
                    flipped=i;
            }
            result=max(result,i-start+1);
        }
        return result;
    }
};