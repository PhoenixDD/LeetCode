class Solution {
public:
    int minSwaps(vector<int>& data) 
    {
        int total1s=0,start=0,count=0,result=INT_MAX;
        for(int &i:data)
            total1s+=i;
        for(int i=0;i<data.size();i++)
        {
            count+=data[i]==1;
            if(i-start+1>total1s)
                count-=data[start++]==1;
            result=min(result,total1s-count);
        }
        return result;
    }
};