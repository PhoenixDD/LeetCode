class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if(needle=="")
            return 0;
        if(haystack=="")
            return -1;
        int needle_pos=0,temp_pos;
        for(int i=0;i<haystack.length();i++)
        {
            if(i+needle.length()>haystack.length())
                return -1;
            if(haystack[i]==needle[needle_pos])
            {
                if(needle.size()==1)
                    return i;
                temp_pos=i+1;
                needle_pos++;
                while(temp_pos<haystack.length()&&haystack[temp_pos]==needle[needle_pos])
                {
                    temp_pos++;
                    needle_pos++;
                    if(needle_pos==needle.size())
                        return i;
                }
                needle_pos=0;
            }
        }
        return -1;
    }
};