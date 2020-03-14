class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int sum=0,result=0;
        for(int i=0;i<k;i++)
            sum+=arr[i];
        result+=(double)sum/k>=threshold;
        for(int i=k;i<arr.size();i++)
            sum=sum-arr[i-k]+arr[i],result+=(double)sum/k>=threshold;
        return result;
    }
};