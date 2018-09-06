class Solution {
public:
    vector<int> count;
    void merge(vector<pair<int,int>> &arr,int start,int mid,int end)
    {
        vector<pair<int,int>> L(arr.begin()+start,arr.begin()+mid+1),R(arr.begin()+mid+1,arr.begin()+end+1);
        int i=0,j=0,s1=mid-start,s2=end-mid-1,begin=start;
        while(i<=s1&&j<=s2)
            if(L[i].first<=R[j].first)
                count[L[i].second]+=start-begin-i,arr[start++]=L[i++];
            else
                arr[start++]=R[j++];
        while(i<=s1)
            count[L[i].second]+=start-begin-i,arr[start++]=L[i++];
        while(j<=s2)
            arr[start++]=R[j++];
    }
    void countSmaller(vector<pair<int,int>>& nums,int start,int end)
    {
        if(start<end)
        {
            int mid=(start+end)/2;
            countSmaller(nums,start,mid);
            countSmaller(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<pair<int,int>> nums2(nums.size());
        count.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++)
            nums2[i]=make_pair(nums[i],i);
        countSmaller(nums2,0,nums2.size()-1);
        return count;
    }
};