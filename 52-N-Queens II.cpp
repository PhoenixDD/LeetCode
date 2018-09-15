class Solution {
public:
    int N,cnt=0;
    vector<int> col;
    bool isvalid(int r,int c)
    {
        for(int i=0;i<r;i++)
            if(col[i]==c||abs(col[i]-c)==abs(i-r))
                return false;
        return true;
    }
    void backtrack(int r)
    {
        if(r==N)
            cnt++;
		else
			for(int c=0;c<N;c++)
				if(isvalid(r,c))
					col[r]=c,backtrack(r+1);
    }
    int totalNQueens(int n)
    {
        N=n;
        col.resize(n,0);
        backtrack(0);
        return cnt;
    }
};