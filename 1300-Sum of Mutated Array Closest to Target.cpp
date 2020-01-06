class Solution {
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        sort(arr.begin(),arr.end());
        int j=0,sum=0,closest=INT_MAX,result,temp=INT_MAX,n=arr.size();
        for(int i=0;i<=1e5&&temp<=closest&&j<arr.size();i++)
        {
            while(j<arr.size()&&arr[j]<i)
                sum+=arr[j++];
            temp=abs(sum+i*(n-j)-target);
            if(temp<closest)
                result=i,closest=temp;
        }
        return result;
    }
};