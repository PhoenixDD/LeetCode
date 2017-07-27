class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty())
            return "";
        else if(strs.size()==1)
            return strs[0];
        else
        {
            int i=0;
            string str="";
            while(i>=0)
            {
                char temp=strs[0][i];
                for(int j=1;j<strs.size();j++)
                {
                    if(i==strs[j].length()||strs[j][i]!=temp)
                        return str;
                }
                str+=temp;
                i++;
            }
        }
    }
};