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
            string result="";
            for(int i=0;i<strs[0].length();i++)
            {
                for(int j=1;j<strs.size();j++)
                    if(i>strs[j].length()||strs[j][i]!=strs[0][i])
                        return result;
                result+=strs[0][i];
            }
            return result;
        }
    }
};