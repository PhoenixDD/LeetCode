class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.resize(numRows);
        vector<int> temp;
        int C;
        for(int i=1;i<=numRows;i++)
        {
            temp.resize(i);
            C=1;
            for(int j=1;j<=i;j++)
                temp[j-1]=C,C=C*(i-j)/j;
            result[i-1]=temp;
        }
        return result;
    }
};