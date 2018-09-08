class Solution {
public: 
    int MOD=1e9+7;
    vector<vector<int>> mul(vector<vector<int>> &A,vector<vector<int>>& B)
    {
        vector<vector<int>> res(6,vector<int>(6,0));
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<6;k++)
                    res[i][j]=(res[i][j]+((long)A[i][k]*B[k][j])%MOD)%MOD;
        return res;
    }
    vector<vector<int>> pow(vector<vector<int>> &A,int n)
    {
        if(!n)
            return {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
        vector<vector<int>> temp=pow(A,n/2);
        if(n&1)
        {
            vector<vector<int>> res=mul(temp,temp);
            return mul(A,res);
        }
        return mul(temp,temp);
    }
    int checkRecord(int n) 
    {
        vector<vector<int>> A={{0,0,1,0,0,0},{1,0,1,0,0,0},{0,1,1,0,0,0},{0,0,1,0,0,1},{0,0,1,1,0,1},{0,0,1,0,1,1}};
        return pow(A,n+1)[5][2];
    }
};