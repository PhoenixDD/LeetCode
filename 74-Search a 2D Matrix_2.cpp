class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int i=0,j=matrix.size()-1,mid,row;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(matrix[mid][0]==target||matrix[mid][matrix[0].size()-1]==target)
                return true;
            else if(matrix[mid][0]<target&&matrix[mid][matrix[0].size()-1]>target)
                {row=mid;break;}
            else if(matrix[mid][0]<target)
                i=mid+1;
            else
                j=mid-1;
                
        }
        i=0,j=matrix[0].size()-1;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]<target)
                i=mid+1;
            else
                j=mid-1;
                
        }
        return false;
    }
};