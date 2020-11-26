/*We use the fact that there are way less numbers that rotate to themselves from the values [0,1,6,8,9] which are the only
values used to create a confusing number. Thus we can simply subtract this number from total possible confusing numbers.*/
static vector<int> all={0,1,6,8,9};
static vector<int> one80={0,1,'x','x','x','x',9,'x',8,6};
static string curr;
static int memo[11][2];
class Solution {
public:
    int getTotalofLengthN(string &n,int cur,bool tight)	//Digit DP
    {
        if(cur==n.length())
            return 1;
        if(memo[cur][tight]!=-1)
            return memo[cur][tight];
        memo[cur][tight]=0;
        for(int &i:all)
        {
            if(tight&&(i+'0'>n[cur]))
                break;
            memo[cur][tight]+=getTotalofLengthN(n,cur+1,tight&&(i+'0'==n[cur]));
        }
        return memo[cur][tight];
    }
    int getTotal(int N)
    {
        memset(memo,-1,sizeof memo);
        int total=0;
        string nStr=to_string(N);
        for(int i=nStr.length()-1;i>=1;i--)		//Simple permutation formula
        {
            int res=1;
            for(int j=1;j<=i;j++)
                res*=j==1?4:5;
            total+=res;
        }
        for(int i=1;i<all.size();i++)
            if(nStr[0]>=all[i]+'0')
                total+=getTotalofLengthN(nStr,1,nStr[0]==all[i]+'0');
        return total;  
    }
    int getSimilar(int& N,int &l,int currLen,long rotation,long curr,long base)	//Rotations tht create similar numbers
    {
        if(l==1)
            return curr==1||curr==8;
        if(currLen==l/2)
        {
            if(l&1)
                return ((curr*10+1)*base+rotation<=N)+((curr*10+8)*base+rotation<=N)+((curr*10)*base+rotation<=N);
            return curr*base+rotation<=N;
        }
        int result=0;
        for(int &i:all)
            result+=getSimilar(N,l,currLen+1,one80[i]*base+rotation,curr*10+i,base*10);
        return result;
    }
    int confusingNumberII(int N)
    {
        int total=getTotal(N);
        int similar=0;
        for(int i=to_string(N).length();i>=1;i--)
            for(int &n:all)
                if(n)
                    similar+=getSimilar(N,i,1,one80[n],n,10);
        return total-similar;
    }
};