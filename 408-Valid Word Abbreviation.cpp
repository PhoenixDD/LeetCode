class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) 
    {
        int prev=0,i=0,j=0,num;
        while(i<abbr.length()&&j<word.length())
        {
            while(i<abbr.length()&&isalpha(abbr[i]))
                if(j<word.length()&&abbr[i++]!=word[j++])
                    return false;
            if(isdigit(abbr[i]))
            {
                if(abbr[i]=='0')
                    return false;
                prev=i;
                while(isdigit(abbr[i]))
                    i++;
                num=stoi(abbr.substr(prev,i-prev));
                j+=num;
            }
        }
        return i==abbr.length()&&j==word.length();
    }
};