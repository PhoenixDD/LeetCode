static vector<char> ones={'0','1','8'};
static vector<char> all={'0','1','6','8','9'};
static vector<char> one80={'0','1','x','x','x','x','9','x','8','6'};
class Solution {
public:
    int dfs(string &low,string &high,string &curr,int i,int j)
    {
        if(curr.front()=='0'&&curr.length()>1)
            return 0;
        if(i>j)
        {
            return curr.length()>low.length()&&curr.length()<high.length()||curr.length()==low.length()&&curr.length()==high.length()&&curr>=low&&curr<=high||curr.length()==high.length()&&curr.length()!=low.length()&&curr<=high||curr.length()==low.length()&&curr.length()!=high.length()&&curr>=low;
        }
        int result=0;
        if(i==j)
        {
            for(char &c:ones)
            {
                curr[i]=c;
                result+=dfs(low,high,curr,i+1,j-1);
            }
            return result;
        }
        for(char &c:all)
        {
            curr[i]=c,curr[j]=one80[c-'0'];
            result+=dfs(low,high,curr,i+1,j-1);
        }
        return result;
    }
    int strobogrammaticInRange(string low, string high)
    {
        if(high.length()<low.length())
            return 0;
        int result=0;
        for(int len=low.length();len<=high.length();len++)
        {
            string curr(len,' ');
            result+=dfs(low,high,curr,0,len-1);
        }
        return result;
    }
};