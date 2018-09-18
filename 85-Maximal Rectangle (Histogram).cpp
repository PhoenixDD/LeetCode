class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if(matrix.empty())
            return 0;
        vector<int> row(matrix[0].size(),0);
        int i,top,max=0;
        stack<int> s;
        for(int row_ind=0;row_ind<matrix.size();row_ind++)
        {
            for(i=0;i<matrix[0].size();i++)
				row[i]=matrix[row_ind][i]=='0'?0:row[i]+1;
            i=0;
            while(i<row.size())
            {
                if(s.empty()||row[i]>=row[s.top()])
                    s.push(i++);
                else
                {
                    top=row[s.top()];
                    s.pop();
                    max=std::max(max,top*(s.empty()?i:i-s.top()-1));
                }
            }
            while(!s.empty())
            {
                top=row[s.top()];
                s.pop();
                max=std::max(max,top*(s.empty()?i:i-s.top()-1));
            }
        }
        return max;
    }
};