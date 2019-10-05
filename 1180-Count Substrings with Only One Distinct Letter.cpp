class Solution {
public:
    int countLetters(string S) 
    {
        char last=S.front();
        int result=0,start=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]!=last)
                last=S[i],start=i;
            result+=i-start+1;
        }
        return result;
    }
};