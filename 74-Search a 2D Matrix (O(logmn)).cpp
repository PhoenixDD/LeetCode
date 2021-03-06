class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int i=0,j=matrix.size()*matrix[0].size()-1,mid;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]==target)
                return true;
            else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]<target)
                i=mid+1;
            else
                j=mid-1;
        }
        return false;
       
    }
};