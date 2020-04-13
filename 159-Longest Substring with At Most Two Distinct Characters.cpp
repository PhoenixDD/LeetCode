static vector<int> counter(128,0);
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        fill(counter.begin(),counter.end(),0);
        int start=0,uniq=0,result=0;
        for(int i=0;i<s.length();i++)
        {
            uniq+=counter[s[i]]++==0;
            while(uniq>2)
                uniq-=counter[s[start++]]--==1;
            result=max(result,i-start+1);
        }
        return result;
    }
};