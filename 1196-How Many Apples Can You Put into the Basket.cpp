class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int result=0,basket=0;
        for(int &i:arr)
        {
            basket+=i;
            if(basket<=5000)
                result++;
            else
                break;
        }
        return result;
    }
};