static vector<int> fib={1,1};
class Solution {
public:
    int findMinFibonacciNumbers(int k)
    {
        while(fib.back()<k)
            fib.push_back(fib.back()+fib[fib.size()-2]);
        vector<int>::iterator it=fib.end();
        int result=0;
        while(k!=0)
        {
            result++;
            it=lower_bound(fib.begin(),it,k);
            if(*it!=k)
                it--;
            k-=*it;
        }
        return result;
    }
};