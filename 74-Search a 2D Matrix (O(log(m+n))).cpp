class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int i=0,j=matrix.size()-1,mid;
        while(i<=j)
        {
            mid=(i+j)>>1;
            if(target>=matrix[mid][0]&&target<=matrix[mid][matrix[0].size()-1])
                return binary_search(matrix[mid].begin(),matrix[mid].end(),target);
            else if(target<matrix[mid][0])
                j=mid-1;
            else
                i=mid+1;
        }
        return false;
    }
};