class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        vector<vector<int>> ARows(A.size()),BCols(B[0].size()),result(A.size(),vector<int>(B[0].size(),0));
        for(int i=0;i<A.size();i++)
            for(int j=0;j<A[i].size();j++)
                if(A[i][j])
                    ARows[i].push_back(j);
        for(int j=0;j<B[0].size();j++)
            for(int i=0;i<B.size();i++)
                if(B[i][j])
                    BCols[j].push_back(i);
        int p1,p2,val;
        for(int i=0;i<ARows.size();i++)
            for(int j=0;j<BCols.size();j++)
            {
                p1=0,p2=0,val=0;
                while(p1<ARows[i].size()&&p2<BCols[j].size())
                {
                    if(ARows[i][p1]<BCols[j][p2])
                        p1++;
                    else if(ARows[i][p1]>BCols[j][p2])
                        p2++;
                    else
                        val+=A[i][ARows[i][p1++]]*B[BCols[j][p2++]][j];
                }
                result[i][j]=val;  
            }
        return result;
    }
};