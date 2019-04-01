//For follow up with Stram of incoming S and same T
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        vector<set<int>> indices(128);
        set<int>::iterator it;
        for(int i=0;i<t.length();i++)
            indices[t[i]].insert(i);
        int start=-1;
        for(char &c:s)
        {
            it=indices[c].upper_bound(start);
            if(it==indices[c].end())
                return false;
            start=*it;
        }
        return true;
    }
};