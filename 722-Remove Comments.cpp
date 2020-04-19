class Solution {
public: 
    vector<string> removeComments(vector<string>& source) 
    {
        vector<string> result;
        string temp;
        bool inBlock=false;
        int i;
        for(string &s:source) 
        {
            if(!inBlock)
                temp="";
            i=0;
            while(i<s.length())
            {
                if(i<s.length()-1&&!inBlock&&s[i]=='/'&&s[i+1]=='*')
                    inBlock=true,i++;
                else if(i<s.length()-1&&inBlock&&s[i]=='*'&&s[i+1]=='/')
                    inBlock=false,i++;
                else if(i<s.length()-1&&!inBlock&&s[i]=='/'&&s[i+1]=='/')
                    break;
                else if(!inBlock)
                    temp+=s[i];
                i++;
            }
            if(temp!=""&&!inBlock)
                result.push_back(temp);
        }
        return result;
    }
};