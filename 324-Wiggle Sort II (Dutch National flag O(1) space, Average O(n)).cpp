//Dutch national flag sorting and finding Median Average O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());                    //get median
        int mid=nums[nums.size()/2],odd=1,even=nums.size()-1-!(nums.size()&1),i=0;          //odd pointer and even pointer
        while(i<nums.size())                                                                //3-Way sorting
        {
            if(nums[i]>mid&&(i%2==0||i>odd))
               swap(nums[i],nums[odd]),odd+=2;
            else if(nums[i]<mid&&(i&1||i<even))
                swap(nums[i],nums[even]),even-=2;
            else
                i++;               
        }
    }
};