static vector<int> counter(128,0);
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        fill(counter.begin(),counter.end(),0);
        int start=0,uniq=0,result=0;
        for(int i=0;i<s.length();i++)
        {
            uniq+=counter[s[i]]++==0;
            while(uniq>k)
                uniq-=counter[s[start++]]--==1;
            result=max(result,i-start+1);
        }
        return result;
    }
};