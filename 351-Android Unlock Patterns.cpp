class Solution {
public:
    vector<vector<int>> memo;
    int n,m;
    bool valid(int i1,int j1,int i2,int j2,int bitvector)
    {
        if(abs(i2-i1)+abs(j2-j1)>1)
        {
            if(abs(i1-i2)==2&&j1==j2)
                return bitvector&1<<((min(i1,i2)+1)*3+j1);
            else if(i1==i2&&abs(j1-j2)==2)
                return bitvector&1<<(i1*3+min(j1,j2)+1);
            else if(abs(i1-i2)==2&&abs(j1-j2)==2)
                return bitvector&1<<4;
        }
        return true;
    }
    int bt(int x,int y,int bitvector,int k) 
    {
        
        if(k==n)
            return 1;
        if(memo[x*3+y][bitvector]!=-1)
            return memo[x*3+y][bitvector];
        int result=k>=m;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if((bitvector&1<<(i*3+j))==0&&valid(x,y,i,j,bitvector))
                    result+=bt(i,j,bitvector|(1<<(i*3+j)),k+1);
        return memo[x*3+y][bitvector]=result;
    }
    int numberOfPatterns(int m, int n) 
    {
        this->n=n,this->m=m;
        memo.resize(10,vector<int>(1024,-1));
        int result=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                result+=bt(i,j,1<<(i*3+j),1);
        return result;
    }
};