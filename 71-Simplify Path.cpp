class Solution {
public:
    string simplifyPath(string path)
    {
        string tmp;
        stack<string> temp;
        stringstream s(path);
        int length=0;
        while(getline(s,tmp,'/'))
        {
            if(tmp==".")
                continue;
            else if(tmp=="..")
            {
                if(!temp.empty())
                    length-=temp.top().length()+1,temp.pop();
            }
            else if(tmp!="")
            {
                temp.push(tmp);
                length+=tmp.length()+1;
            }
        }
        path.resize(length);
        if(temp.empty())
            return "/";
        while(!temp.empty())
        {
            for(int i=temp.top().length()-1;i>=0;i--)
            {
                path[--length]=temp.top()[i];
            }
            path[--length]='/';
            temp.pop();
        }
        return path;
    }
};