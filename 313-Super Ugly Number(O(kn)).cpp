class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        vector<int> result(n,INT_MAX),idx(primes.size(),0);
        result[0]=1;
        int index=1;
        while(--n)
        {
            for(int i=0;i<primes.size();i++)
            {
                if(result[index-1]==result[idx[i]]*primes[i])
                    idx[i]++;
                result[index]=min(result[idx[i]]*primes[i],result[index]);
            }
            index++;
        }
        return result[index-1];
    }
};