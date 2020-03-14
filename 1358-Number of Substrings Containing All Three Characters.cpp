class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        vector<int> count={0,0,0};
        int result=0,start=0;
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
            while(count[0]&&count[1]&&count[2])
                count[s[start++]-'a']--;
            result+=i-start+1;
        }
        return s.size()*(s.size()+1)/2-result;
            
    }
};