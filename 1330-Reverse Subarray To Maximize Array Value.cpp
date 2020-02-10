/**
Gain after swap of i-1,[i...j],j+1 = 2*(a[j]-a[i]])
**/
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) 
    {
        int total=0,end=INT_MAX,start=0,diff;
        for(int i=1;i<nums.size();i++)                                 //Get the current total
            total+=abs(nums[i]-nums[i-1]);
        for(int i=1;i<nums.size();i++)                                //Find the start and end points to rotate between 0 and n exclusive.
            end=min(end,max(nums[i],nums[i-1])),start=max(start,min(nums[i],nums[i-1]));
        diff=2*(start-end);
        for(int i=1;i<nums.size();i++)              //Do it for the two edge cases rotating from 0...i or i..(n-1)
        {
		    diff=max(diff,abs(nums[0]-nums[i])-abs(nums[i]-nums[i-1]));
		    diff=max(diff,abs(nums[nums.size()-1]-nums[i-1])-abs(nums[i]-nums[i-1]));
	    }
	    return total+diff;
    }
};