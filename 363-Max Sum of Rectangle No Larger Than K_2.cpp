class Solution {
public:
    int Max=INT_MIN,K;
    void get_max(vector<int>& nums)                                         //Get max no larger than K in a single dimensional array
    {
        int sum=0;
        set<int> sorted_sum;
        set<int>::iterator it;
        sorted_sum.insert(0);
        for(int &i:nums)
        {
            sum+=i;
            it=sorted_sum.lower_bound(sum-K);
            if(it!=sorted_sum.end())
                Max=max(Max,sum-*it);
            sorted_sum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        K=k;
        if(matrix[0].size()>matrix.size())                                          //Convert 2D Array to 1D by rows
        {
            vector<int> row(matrix[0].size());
            for(int i=0;i<matrix.size();i++)
            {
                fill(row.begin(),row.end(),0);
                for(int j=i;j<matrix.size();j++)
                {
                    for(int x=0;x<matrix[0].size();x++)
                        row[x]+=matrix[j][x];
                    get_max(row);
                    if(Max==k)
                        return Max;
                }
            }
        }
        else                                                                       ////Convert 2D Array to 1D by columns
        {
            vector<int> row(matrix.size());
            for(int i=0;i<matrix[0].size();i++)
            {
                fill(row.begin(),row.end(),0);
                for(int j=i;j<matrix[0].size();j++)
                {
                    for(int x=0;x<matrix.size();x++)
                        row[x]+=matrix[x][j];
                    get_max(row);
                    if(Max==k)
                        return Max;
                }
            }
        }
        return Max;
    }
};