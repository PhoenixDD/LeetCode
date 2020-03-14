static int encountered[32];
class Solution {
public:
    int getId(char &c)   //For hashing in bit vector
    {
        switch(c)
        {
            case 'a': return 1;
            case 'e': return 2;
            case 'i': return 4;
            case 'o': return 8;
            case 'u': return 16;
            default: return 0;
        };
        return 0;
    }
    int findTheLongestSubstring(string s) 
    {
        int bitvec=0,result=0;
        memset(encountered,-2,sizeof encountered);
        encountered[0]=-1;  //We need to consider the entire string in case of 0 for eg: bcbcbc.
        for(int i=0;i<s.length();i++)
        {
            bitvec^=getId(s[i]);
            if(encountered[bitvec]==-16843010)
                encountered[bitvec]=i;
            result=max(result,i-encountered[bitvec]);   //We dont count the starting character so no + 1.
        }
        return result;
    }
};