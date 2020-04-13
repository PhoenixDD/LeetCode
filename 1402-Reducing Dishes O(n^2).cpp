class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int Max=0,sum;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<satisfaction.size();i++)
        {
            sum=0;
            for(int j=i,count=1;j<satisfaction.size();j++,count++)
                sum+=satisfaction[j]*count;
            Max=max(Max,sum);
        }
        return Max;
    }
};