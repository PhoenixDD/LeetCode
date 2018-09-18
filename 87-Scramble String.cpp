class Solution {
public:
    vector<int> counter;
    bool isScramble(string &s1, string &s2,int i,int j,int length)
    {
        if(!s1.compare(i,length,s2,j,length))
            return true;
        fill(counter.begin(),counter.end(),0);
        for(int x=0;x<length;x++)
            counter[s1[i+x]-'a']++,counter[s2[j+x]-'a']--;
        for(int x=0;x<counter.size();x++)
            if(counter[x])
                return false;
        for(int l=1;l<length;l++)
            if(isScramble(s1,s2,i,j,l)&&isScramble(s1,s2,i+l,j+l,length-l)||isScramble(s1,s2,i+length-l,j,l)&&isScramble(s1,s2,i,j+l,length-l))
                return true;
        return false;
    }
    bool isScramble(string s1, string s2) 
    {
		counter.resize(26);
        return isScramble(s1,s2,0,0,s1.length());
    }
};