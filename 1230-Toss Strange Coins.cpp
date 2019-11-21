class Solution {
public:
    vector<vector<double>> memo;
    double dp(vector<double>& prob,int i,int target)
    {
        if(memo[i][target]!=-1)
            return memo[i][target];
        if(target==0)
        {
            double result=1;
            for(int d=0;d<i;d++)
                result*=1-prob[d];
            return memo[i][target]=result;
        }
        if(i==0)
            return memo[i][target]=0;
        return memo[i][target]=prob[i-1]*dp(prob,i-1,target-1)+(1-prob[i-1])*dp(prob,i-1,target);
    }
    double probabilityOfHeads(vector<double>& prob, int target) 
    {
        memo.resize(prob.size()+1,vector<double>(target+1,-1));
        return dp(prob,prob.size(),target);
    }
};