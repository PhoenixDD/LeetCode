class Solution {
public:
    string minWindow(string s, string t) 
    {
        int begin=0,start=-1,Min=INT_MAX,size=t.length();
        vector<int> map(128,0);
        for(char &c:t)
            map[c]++;
        for(int i=0;i<s.length();i++)
        {
            if(map[s[i]]-->0)
                size--;
            while(!size)
            {
                if(Min>i-begin+1)
                    Min=i-begin+1,start=begin;
                if(map[s[begin++]]++==0)
                    size++;
            }
        }
        return start==-1?"":s.substr(start,Min);
    }
};