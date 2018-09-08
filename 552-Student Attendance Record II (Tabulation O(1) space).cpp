class Solution {
public: 
    int checkRecord(int n) 
    {
        vector<vector<int>> prev(2,vector<int>(3,1)),next(2,vector<int>(3));
        int MOD=1e9+7;
        for(int i=1;i<=n;i++)
        {
            for(int A=0;A<2;A++)
                for(int L_count=0;L_count<3;L_count++)
                {
                    if(A)
                    {
                        if(L_count==2)
                            next[A][L_count]=prev[1][0]%MOD;
                        else
                            next[A][L_count]=(prev[1][0]+prev[1][L_count+1])%MOD;
                    }
                    else
                    {
                        if(L_count==2)
                            next[A][L_count]=(prev[1][0]+prev[0][0])%MOD;
                        else
                            next[A][L_count]=((long)prev[1][0]+prev[0][0]+prev[0][L_count+1])%MOD;
                    }
                }
            prev.swap(next);
        }
        return prev[0][0];
    }
};