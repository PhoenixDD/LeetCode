class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<int> diffWaysToCompute(string &input,int start,int end)
    {
        if(start>end)
            return {};
        if(!memo[start][end].empty())
            return memo[start][end];
        vector<int> result;
        for(int i=start;i<=end;i++)
        {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*')
            {
                vector<int> left=diffWaysToCompute(input,start,i-1),right=diffWaysToCompute(input,i+1,end);
                for(int &l:left)
                    for(int &r:right)
                        if(input[i]=='+')
                            result.push_back(l+r);
                        else if(input[i]=='-')
                            result.push_back(l-r);
                        else
                            result.push_back(l*r);
            }
        }
        if(result.empty())
            return memo[start][end]={stoi(input.substr(start,end-start+1))};
        return memo[start][end]=result;
    }
    vector<int> diffWaysToCompute(string input)
    {
        memo.resize(input.size(),vector<vector<int>>(input.size()));
        return diffWaysToCompute(input,0,input.length()-1);
    }
};