class Solution {
public:
    int countPrimes(int n) 
    {
        if(n<3)
            return 0;
        int count=n/2;
        vector<bool> primes(n,true);
        for(int i=3;i*i<n;i+=2)
            for(int j=i*i;j<n;j+=2*i)
                if(primes[j])
                    primes[j]=false,count--;
        return count;
    }
};