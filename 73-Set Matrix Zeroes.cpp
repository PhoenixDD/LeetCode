class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool row=false,col=false;
        for(int i=0;i<matrix.size();i++)
            if(!matrix[i][0])
                {col=true;break;}
        for(int i=0;i<matrix[0].size();i++)
            if(!matrix[0][i])
                {row=true;break;}
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(!matrix[i][j])
                    matrix[0][j]=0,matrix[i][0]=0;
        for(int i=1;i<matrix.size();i++)
            if(!matrix[i][0])
                for(int j=1;j<matrix[0].size();j++)
                    matrix[i][j]=0;
        for(int i=1;i<matrix[0].size();i++)
            if(!matrix[0][i])
                for(int j=1;j<matrix.size();j++)
                    matrix[j][i]=0;
        if(row)
            for(int i=0;i<matrix[0].size();i++)
                matrix[0][i]=0;
         if(col)
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
        
    }
};