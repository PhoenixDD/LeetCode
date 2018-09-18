class Solution {
public:
    vector<vector<int>> pal_memo;
    bool ispal(string &s,int i,int j)
    {
        if(pal_memo[i][j]!=-1)
            return pal_memo[i][j];
        if(i==j)
            return pal_memo[i][j]=true;
        if(i==j-1&&s[i]==s[j])
            return pal_memo[i][j]=true;
        if(s[i]==s[j]&&ispal(s,i+1,j-1))
        {
            ispal(s,i+1,j);
            ispal(s,i,j-1);
            return pal_memo[i][j]=true;
        }
        ispal(s,i+1,j);
        ispal(s,i,j-1);
        return pal_memo[i][j]=false; 
    }
    vector<vector<string>> result;
    vector<string> temp;
    void partition(string &s,int i,int j)
    {
        if(i==s.length())
        {
			result.push_back(temp);
			return;
		}
        for(int k=i;k<j;k++)
            if(pal_memo[i][k])
            {
                temp.push_back(s.substr(i,k-i+1));
                partition(s,k+1,j);
                temp.pop_back();
            }
            
    }
    vector<vector<string>> partition(string s)
    {
        if(s.empty())
            return result;
        temp.reserve(s.length());
        pal_memo.resize(s.length(),vector<int>(s.length(),-1));
        ispal(s,0,s.length()-1);
        partition(s,0,s.length());
        return result;
    }
};