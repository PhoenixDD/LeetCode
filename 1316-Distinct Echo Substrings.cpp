static int MOD=1e9+7,BASE=51;
/*
hash[L] = hash[0] * BASE^(L-1) + hash[1] * BASE^(L-2) + ... + hash[L-1] * BASE
hash[r] = hash[0] * BASE^(r-1) + hash[1] * BASE^(r-2) + ... + hash[L] * BASE^(r-L) + ... + hash[r] * BASE
hash[L-r] = hash[L] * BASE^(r-L) + hash[L+1] * BASE^(r-L-1) + ... hash[r] * BASE
*/
class Solution {
public:
    int distinctEchoSubstrings(string text) 
    {
        unordered_set<int> results;
        vector<long> pow(text.length()+1,1),hash(text.length()+1,0);
        int hashL,hashR;
        for(int i=0;i<text.length();i++)
            hash[i+1]=(hash[i]*BASE+text[i]-'a'+1)%MOD,pow[i+1]=(pow[i]*BASE)%MOD;
        for(int l=1;l<=text.length()/2;l++)
            for(int i=0;i+l*2<=text.length();i++)
            {
                hashL=(((hash[i+l]-hash[i]*pow[i+l-i])%MOD)+MOD)%MOD; //Like prefix sum right-left*pow[right-left]
                hashR=(((hash[i+2*l]-hash[i+l]*pow[i+2*l-i-l])%MOD)+MOD)%MOD;
                if(hashL==hashR)
                    results.insert(hashL);
            }
        return results.size();
    }
};