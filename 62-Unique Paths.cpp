class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if(m==1||n==1)
            return 1;
        long C=1;
        m--;
        n=m+n-1;
        if(m>n/2)
            m=n-m;
        for (int i=1;i<=m;i++)
            C=C*(n+1-i)/i;
        return C;
    }
};