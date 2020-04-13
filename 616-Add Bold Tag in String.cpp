class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) 
    {
        int prev,i=0;
        vector<bool> isBold(s.length(),false);
        string result;
        for(string &w:dict)
        {
            prev=-1;
            while(true)
            {
                prev=s.find(w,prev+1);
                if(prev==string::npos)
                    break;
                fill(isBold.begin()+prev,isBold.begin()+prev+w.size(),true);
            }
        }
        while(i<s.length())
        {
            if(isBold[i])
            {
                result+="<b>";
                while(i<s.length()&&isBold[i])
                    result+=s[i++];
                result+="</b>";
            }
            else
                while(i<s.length()&&!isBold[i])
                    result+=s[i++];
        }
        return result;
    }
};