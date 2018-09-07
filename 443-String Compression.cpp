class Solution {
public:
    int compress(vector<char>& chars)
    {
        string temp;
        int count,start=0;
        for(int end=0;end<chars.size();end++)
        {
            count=1;
            while(end<chars.size()-1&&chars[end]==chars[end+1])
                count++,end++;
            chars[start++]=chars[end];
            if(count!=1)
            {
                temp=to_string(count);
                for(int i=0;i<temp.length();i++)
                    chars[start++]=temp[i];
            }
        }
        chars.resize(start);
        return start;
    }
};