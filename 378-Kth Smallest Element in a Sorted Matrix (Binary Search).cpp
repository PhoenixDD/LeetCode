class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int start=matrix[0][0],end=matrix[matrix.size()-1][matrix[0].size()-1],mid,count,j;
        while(start<end)
        {
            mid=(start+end)>>1,j=matrix[0].size()-1,count=0;
            for(int i=0;i<matrix.size();i++)
            {
                while(j>=0&&matrix[i][j]>mid)
                    j--;
                count+=(j+1);
            }
            if(count<k)
                start=mid+1;
            else
                end=mid;
        }
        return start;
    }
};