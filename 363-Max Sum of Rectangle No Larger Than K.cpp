class Solution {
public:
    int Max=INT_MIN,K;
    void merge(vector<int> &arr,int start,int mid,int end)
    {
        for(int i=start,j=mid+1;i<=mid&&j<=end;)
            if(arr[j]-arr[i]<=K)
                Max=max(Max,arr[j++]-arr[i]);
            else
                i++;
        inplace_merge(arr.begin()+start,arr.begin()+mid+1,arr.begin()+end+1);
    }
    void mergesort(vector<int>& nums,int start,int end)
    {
        if(start<end)
        {
            int mid=(start+end)/2;
            mergesort(nums,start,mid);
            mergesort(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        K=k;
        if(matrix[0].size()>matrix.size())
        {
            vector<int> row(matrix[0].size()),sum(matrix[0].size()+1);
            for(int i=0;i<matrix.size();i++)
            {
                fill(row.begin(),row.end(),0);
                for(int j=i;j<matrix.size();j++)
                {
                    for(int x=0;x<matrix[0].size();x++)
                        row[x]+=matrix[j][x];
                    sum[0]=0;
                    for(int x=0;x<row.size();x++)
                        sum[x+1]=sum[x]+row[x];
                    mergesort(sum,0,sum.size()-1);
                    if(Max==k)
                        return Max;
                }
            }
        }
        else
        {
            vector<int> row(matrix.size()),sum(matrix.size()+1);
            for(int i=0;i<matrix[0].size();i++)
            {
                fill(row.begin(),row.end(),0);
                for(int j=i;j<matrix[0].size();j++)
                {
                    for(int x=0;x<matrix.size();x++)
                        row[x]+=matrix[x][j];
                    sum[0]=0;
                    for(int x=0;x<row.size();x++)
                        sum[x+1]=sum[x]+row[x];
                    mergesort(sum,0,sum.size()-1);
                    if(Max==k)
                        return Max;
                }
            }
        }
        return Max;
    }
};