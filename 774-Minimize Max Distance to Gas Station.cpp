class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) 
    {
        double i=0,j=0,mid;
        int count;
        for(int i=1;i<stations.size();i++)
            j=max(j,(double)stations[i]-stations[i-1]);
        while(j-i>1e-6)
        {
            mid=(i+j)/2;
            count=0;
            for(int i=1;i<stations.size();i++)
                count+=(stations[i]-stations[i-1])/mid;
            if(count>K)
                i=mid;
            else
                j=mid;       
        }
        return i;
    }
};