class Solution {
public:
    string boldWords(vector<string>& words, string S) 
    {
        vector<bool> isBold(S.length(),false);
        int prev;
        for(string &w:words)
        {
            prev=-1;
            while(true)
            {
                prev=S.find(w,prev+1);
                if(prev==string::npos)
                    break;
                fill(isBold.begin()+prev,isBold.begin()+prev+w.length(),true);
            }
        }
        bool inBold=false;
        string result;
        for(int i=0;i<S.length();i++)
        {
            if(isBold[i]&&!inBold)
                inBold=true,result+="<b>";
            else if(!isBold[i]&&inBold)
                inBold=false,result+="</b>";
            result+=S[i];
        }
        if(isBold.back())
            result+="</b>";
        return result;
    }
};