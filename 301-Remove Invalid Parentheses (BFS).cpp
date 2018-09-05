class Solution {
public:
    bool valid;
    bool isvalid(string &s)
    {
        int count=0;
        for(char &c:s)
        {
            if(c=='(')
                count++;
            else if(c==')')
                count--;
            if(count<0)
                return valid=false;
        }
        return valid=count==0;
    }
    vector<string> removeInvalidParentheses(string s) 
    {
        if(s.empty())
            return {""};
        if(isvalid(s))
            return {s};
        unordered_set<string> visited;
        vector<string> result;
        bool found=false;
        queue<string> q;
        q.push(s);
        int size;
        string temp;
        while(!q.empty())
        {
            size=q.size();
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<q.front().length();j++)
                {
                    if(q.front()[j]=='('||q.front()[j]==')')
                    {
                        temp=q.front().substr(0,j)+q.front().substr(j+1,q.front().length()-j+2);
                        if(visited.find(temp)==visited.end())
                        {
                            if(isvalid(temp))
                                found=true;
                            if(found)
                            {
                                if(valid)
                                    result.push_back(temp);
                            }
                            else
                                q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
                q.pop();
            }
            if(found)
                return result;
        }
        return {""};
    }
};