//Same as 410. Split Array Largest Sum difference of upper_bound
class Solution {
public:
    int K;
    bool isValid(vector<int>& sweetness,int target)
    {
        int sum=0,count=0;
        for(int &i:sweetness)
        {
            sum+=i;
            if(sum>target)
            {
                if(++count==K)
                    return true;
                sum=0;
            }
        }
        return false;
    }
    int maximizeSweetness(vector<int>& sweetness, int K) 
    {
        long j=0,mid;
        int i=1e6;
        for(int &s:sweetness)
            j+=s,i=min(i,s);
        if(K==0)
            return j;
        this->K=K+1;
        while(i<j)              //Upper_bound
        {
            mid=(i+j)>>1;
            if(isValid(sweetness,mid))
                i=mid+1;
            else
                j=mid;         
        }
        return i;
    }
};