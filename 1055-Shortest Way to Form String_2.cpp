class Solution {
public:
    int shortestWay(string source, string target) 
    {
        vector<vector<int>> indices(26);
        vector<int> pointers(26,0);
        int i;
        for(int i=0;i<source.length();i++)
            indices[source[i]-'a'].push_back(i);
        int index=0,result=1;
        for(char &c:target)
        {
            if(indices[c-'a'].empty())
                return -1;
            while(indices[c-'a'][pointers[c-'a']]<index)
            {
                pointers[c-'a']++;
                if(pointers[c-'a']>=indices[c-'a'].size())
                    fill(pointers.begin(),pointers.end(),0),index=0,result++;
            }
            index=indices[c-'a'][pointers[c-'a']]+1;
        }
        return result;
    }
};