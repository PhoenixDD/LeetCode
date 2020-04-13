//Intelligent optimization to O(n^2) solution.
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int sum=0,result=0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=satisfaction.size()-1;i>=0&&sum+satisfaction[i]>0;i--)
        {
            sum+=satisfaction[i];
            result+=sum;
        }
        return result;
    }
};