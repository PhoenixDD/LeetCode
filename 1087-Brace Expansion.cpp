class Solution {
public:
    vector<string> result;
    string temp;
    void expandFromList(string &s,int i,bool isSelected)
    {
        int next=s.find_first_of(",}",i);
        if(!isSelected)
        {
            string word=s.substr(i,next-i);
            temp+=word;
            if(s[next]=='}')
                expand(s,next+1);
            else
                expandFromList(s,next+1,true);
            temp.pop_back();
            if(s[next]!='}')
                expandFromList(s,next+1,false);
        }
        else
        {
            if(s[next]=='}')
                expand(s,next+1);
            else
                expandFromList(s,next+1,true);
        }
    }
    void expand(string &s,int i)
    {
        if(i==s.length())
        {
            result.push_back(temp);
            return;
        }
        if(s[i]=='{')
            expandFromList(s,i+1,false);
        else
        {
            temp+=s[i];
            expand(s,i+1);
            temp.pop_back();
        }
            
    }
    vector<string> expand(string S) 
    {
        expand(S,0);
        sort(result.begin(),result.end());
        return result;
    }
};