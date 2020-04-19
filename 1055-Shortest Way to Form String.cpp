class Solution {
public:
    int shortestWay(string source, string target) 
    {
        vector<vector<int>> indices(26);
        int i;
        for(int i=0;i<source.length();i++)
            indices[source[i]-'a'].push_back(i);
        int index=0,result=1;
        char prev='-';
        for(char &c:target)
        {
            if(indices[c-'a'].empty())
                return -1;
            i=lower_bound(indices[c-'a'].begin(),indices[c-'a'].end(),prev==c?index+1:index)-indices[c-'a'].begin();
            if(i>=indices[c-'a'].size())
                result++,i=0;
            index=indices[c-'a'][i];
            prev=c;
        }
        return result;
    }
};