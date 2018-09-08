class Solution {
public:
    int MOD=1e9+7;
    vector<vector<vector<int>>> memo;
    int checkRecord(int n,bool A,int L_count) 
    {
        if(!n)
            return 1;
        if(memo[A][L_count][n]!=-1)
            return memo[A][L_count][n];
        if(A)
        {
            if(L_count==2)
                memo[A][L_count][n]=checkRecord(n-1,true,0);
            else
                memo[A][L_count][n]=checkRecord(n-1,true,0)+checkRecord(n-1,true,L_count+1);
        }
        else
        {
            if(L_count==2)
                memo[A][L_count][n]=checkRecord(n-1,true,0)+checkRecord(n-1,false,0);
            else
                memo[A][L_count][n]=(((long)checkRecord(n-1,true,0)+checkRecord(n-1,false,0)+checkRecord(n-1,false,L_count+1))%MOD);
        }
        return memo[A][L_count][n]%=MOD;
    }
    int checkRecord(int n) 
    {
        memo.resize(2,vector<vector<int>>(3,vector<int>(n+1,-1)));
        return checkRecord(n,false,0);
    }
};