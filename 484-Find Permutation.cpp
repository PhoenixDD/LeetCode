class Solution {
public:
    vector<int> findPermutation(string s)
    {
        vector<int> result;
        for(int i=1;i<=s.length()+1;i++)
            result.push_back(i);
        int start=0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='D')
            {
                start=i;
                while(i<s.length()&&s[i]=='D')
                    i++;
                reverse(result.begin()+start,result.begin()+i+1);
            }
        return result;
    }
};