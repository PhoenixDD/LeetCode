static vector<int> sums(37,0);
class Solution {
public:
    int s(int n)
    {
        int sum=0;
        while(n)
            sum+=n%10,n/=10;
        return sum;
    }
    int countLargestGroup(int n) 
    {
        fill(sums.begin(),sums.end(),0);
        int Max=0,count=0,temp;
        for(int i=1;i<=n;i++)
        {
            temp=++sums[s(i)];
            if(temp>Max)
                Max=temp,count=0;
            count+=temp==Max;
        }
        return count;
    }
};