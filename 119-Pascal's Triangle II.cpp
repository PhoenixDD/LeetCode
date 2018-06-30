class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        result.resize(rowIndex+1,1);
        for(int r=1;r<=rowIndex;r++)
            result[r]=result[r-1]*(long)(rowIndex+1-r)/r;
        return result;
    }
};