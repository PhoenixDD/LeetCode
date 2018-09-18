class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        result.resize(numRows);
        int C;
        for(int i=1;i<=numRows;i++)
        {
            C=1;
            for(int j=1;j<=i;j++)
                result[i-1].push_back(C),C=C*(i-j)/j;
        }
        return result;       
    }
};