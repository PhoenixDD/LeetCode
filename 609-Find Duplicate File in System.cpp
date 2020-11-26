static int MOD=1e9+7,BASE=101;
class Solution {
public:
    int getHash(string &s,int start,int end)
    {
        long long result=0;
        for(int i=start;i<=end;i++)
            result=((result*BASE)%MOD+s[i])%MOD;
        return result;            
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
        unordered_map<int,vector<string>> contentPaths;
        vector<vector<string>> result;
        string path,fileName;
        int i,prev;
        for(string &p:paths)
        {
            i=0;
            i=p.find(' ');
            path=p.substr(0,i);
            i++;
            prev=i;
            while(prev<p.length())
            {
                i=p.find('(',prev);
                fileName=p.substr(prev,i-prev);
                prev=i+1;
                i=p.find(')',prev);
                contentPaths[getHash(p,prev,i-1)].push_back(path+'/'+fileName);
                prev=i+2;
            }
        }
        for(auto &kv:contentPaths)
            if(kv.second.size()>=2)
                result.push_back(kv.second);
        return result;
        
    }
};