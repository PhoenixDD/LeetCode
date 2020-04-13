//A days window of size start,i+1....i+k,end is valid if all days[end] < i...i+k > days[start]
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K)
    {
        int start=0,end=K+1,result=20001;
        vector<int> days(bulbs.size());
        for(int i=0;i<bulbs.size();i++)
            days[bulbs[i]-1]=i+1;
        for(int i=0;end<bulbs.size();i++)
            if(days[i]<days[start]||days[i]<=days[end])
            {
                if(i==end)
                    result=min(result,max(days[start],days[end]));
                start=i;
                end=i+K+1;
            }
        return result==20001?-1:result;
    }
};