class Solution {
public:
    string smallestGoodBase(string n) 
    {
        unsigned long long sum,num,x,N=stoll(n);
        for(int i=log2(N)+1;i>2;i--)
        {
            num=pow((double)N,(double)1/(i-1));
            sum=1;
            x=num;
            for(int p=1;p<i;p++)
                sum+=x,x*=num;
            if(sum==N)
                return to_string(num);
        }
        return to_string(N-1);
    }
};