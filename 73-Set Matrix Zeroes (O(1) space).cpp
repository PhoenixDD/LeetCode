class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool iscol=false,isrow=false;
        for(int &i:matrix[0])
            if(!i)
            {isrow=true;break;}
        for(int i=0;i<matrix.size();i++)
            if(!matrix[i][0])
            {iscol=true;break;}
        for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++)
                if(!matrix[i][j])
                    matrix[0][j]=0,matrix[i][0]=0;
        for(int i=1;i<matrix[0].size();i++)
            if(!matrix[0][i])
                for(int j=0;j<matrix.size();j++)
                    matrix[j][i]=0;
        for(int i=1;i<matrix.size();i++)
            if(!matrix[i][0])
                fill(matrix[i].begin(),matrix[i].end(),0);
        if(iscol)
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
        if(isrow)
            fill(matrix[0].begin(),matrix[0].end(),0);
    }
};