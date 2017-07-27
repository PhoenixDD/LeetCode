class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if(nums.empty()||nums.size()<4)
            return result;
        bool break_flag=false;
        vector<int> temp(4);
        sort(nums.begin(),nums.end());
        for(int l=0;l<nums.size()-3;l++)
        {
            if(l!=0&&nums[l]==nums[l-1])
                continue;
            for(int i=l+1;i<nums.size()-2;i++)
            {
                if(i!=l+1&&nums[i]==nums[i-1])
                    continue;
                int j=i+1,k=nums.size()-1;
                while(j<k)
                {
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                    {
                        temp[0]=nums[l];temp[1]=nums[i];temp[2]=nums[j];temp[3]=nums[k];
                        result.push_back(temp);
                        cout<<j<<" "<<k<<endl;
                        while(j<k&&nums[j]==nums[j+1])
                            j++;
                        while(j<k&&nums[k]==nums[k-1])
                            k--;
                        j++;k--;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]<target)
                        j++;
                    else
                        k--;
                }
            }
        }
        return result;
    }
};