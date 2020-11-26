int counts[51][26];
class Solution {
public:
    vector<bool> shouldChoose;
    int best=INT_MAX;
    int getMaxPossible(vector<string>& stickers,int idx,int chars[26])
    {
        int result=0;
        for(int i=0;i<26;i++)
            if(chars[i]&&counts[idx][i])
                result=max(result,chars[i]);
        return result;
    }
    void remove(vector<string>& stickers,int idx,int to[26],int count)
    {
        while(count--)
            for(int i=0;i<26;i++)
                to[i]-=min(to[i],counts[idx][i]);
    }
    bool isEmpty(int chars[26])
    {
        for(int i=0;i<26;i++)
            if(chars[i])
                return false;
        return true;
    }
    void dfs(vector<string>& stickers,int start,int chars[26],int result)
    {
        if(result>=best)
            return;
        if(start==0)
        {
            if(isEmpty(chars))
                best=min(result,best);
            return;
        }
        if(!shouldChoose[start-1])
            return dfs(stickers,start-1,chars,result);
        int temp[26],Max=getMaxPossible(stickers,start-1,chars);
        for(int i=0;i<=Max;i++)
        {
            memcpy(temp,chars,sizeof(temp));
            remove(stickers,start-1,temp,i);
            dfs(stickers,start-1,temp,i+result);
        }
    }
    int minStickers(vector<string>& stickers, string target) 
    {
        sort(stickers.begin(),stickers.end(),[](string &l,string &r){return l.length()>r.length();});
        memset(counts,0,sizeof counts);
        shouldChoose.resize(stickers.size(),true);
        for(int i=0;i<stickers.size();i++)
            for(char &c:stickers[i])
                counts[i][c-'a']++;
        int temp[26]={0};
        for(char &c:target)
            temp[c-'a']++;
        for(int i=0;i<stickers.size();i++)
            for(int j=i+1;j<stickers.size();j++)
            {
                int k;
                for(k=0;k<26;k++)
                    if(temp[k]>counts[i][k]&&counts[j][k]>counts[i][k])
                        break;
                if(k==26)
                   shouldChoose[j]=false;
            }
        dfs(stickers,stickers.size(),temp,0);
        return best==INT_MAX?-1:best;
    }
};