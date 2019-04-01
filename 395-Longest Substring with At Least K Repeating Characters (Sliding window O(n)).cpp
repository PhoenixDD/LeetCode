/*
Sliding window on number of letters with count k rather than index O(n)
*/
class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        unordered_map<char,int> count(26);
        int counter=1,start,count_k,diffchars,result=0;
        for(char &c:s)
            count[c]++;
        for(char c='a';c<='z';c++)                          // Get max number of k times repeating characters
            if(count[c]>=k)
                counter++;
        while(--counter)                                    //Start with max uptil 1 charater that repeats k times
        {
            start=0,count_k=0,diffchars=0;
            count.clear();
            for(int i=0;i<s.length();i++)
            {
                if(count[s[i]]++==0)                        //track different number of characters
                    diffchars++;
                if(count[s[i]]==k)                          //Track characters which have repeated k times
                    count_k++;
                while(diffchars>counter&&start<i)           //minimize window
                {
                    if(count[s[start]]--==k)
                        count_k--;
                    if(count[s[start]]==0)
                        diffchars--;
                    start++;
                }
                if(count_k==diffchars)          //If number of characters encountered equals to number of characters with count k or more
                    result=max(result,i-start+1);
            }
        }
        return result;
    }
};