class Solution {
public:
    vector<vector<int>> pal_memo;
    vector<vector<vector<string>>> memo;
    bool create_pal_memo(string &s,int i,int j)
    {
        if(pal_memo[i][j]!=-1)
            return pal_memo[i][j];
        else if(i==j)
            return pal_memo[i][j]=true;
        else if(i==j-1&&s[i]==s[j])
            return pal_memo[i][j]=true;
        create_pal_memo(s,i+1,j);
        create_pal_memo(s,i,j-1);
        if(s[i]==s[j]&&create_pal_memo(s,i+1,j-1))
            return pal_memo[i][j]=true;
        return pal_memo[i][j]=false;
    }
    vector<vector<string>> part(string &s,int i)
    {
        if(i==s.length())
            return {{""}};
        if(!memo[i].empty())
            return memo[i];
        vector<vector<string>> result;
        vector<vector<string>> temp;
        string tmp;
        for(int end=i;end<s.length();end++)
        {
            if(pal_memo[i][end])
            {
                tmp=s.substr(i,end-i+1);
                temp=part(s,end+1);
                for(vector<string> &vs:temp)
                {
                    result.push_back({tmp});
                    if(!vs[0].empty())
                        result.back().insert(result.back().end(),vs.begin(),vs.end());
                }
            }
        }
        return memo[i]=result;
    }
    vector<vector<string>> partition(string s) 
    {
        if(s.empty())
            return{{}};
        pal_memo.resize(s.length(),vector<int>(s.length(),-1));
        memo.resize(s.length());
        create_pal_memo(s,0,s.length()-1);
        return part(s,0);
    }
};