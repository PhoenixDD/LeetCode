class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int j,k,result=0;
        for(int i=0;i<(int)nums.size()-2;i++)
        {
            j=i+1,k=(int)nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]<target)
                    result+=k-j++;
                else
                    k--;
            }
        }
        return result;
    }
};