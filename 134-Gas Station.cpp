class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int j,k,sum;
        for(int i=0;i<cost.size();i+=j)
        {
            sum=0;
            for(j=1;j<=cost.size();j++)
            {
                k=(i+j-1)%cost.size();
                sum+=gas[k]-cost[k];
                if(sum<0)
                    break;
            }
            if(j>cost.size())
                return i;
        }
        return -1;
    }
};