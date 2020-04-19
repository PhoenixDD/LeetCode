/*Dancing pointer approach
We keep increasing the pointer for T for each match, once we get to the end we know that the last index matches the last character and ofcourse the subsequence couldn't have ended before that, but for the start we are not so sure thus we optimize the start by matching from the end(This makes us sure that we have the shortest sequence). We then start from the next character(the start point we just found). This is as we might find a shorter distance starting from the next character rather than the end as it could also create a partial subseqence within the found subsequence.
*/
class Solution {
public:
    string minWindow(string S, string T) 
    {
        int end=0,tIndex=0,result=INT_MAX,s;
        for(int i=0;i<S.length();i++)
        {
            tIndex+=S[i]==T[tIndex];
            if(tIndex==T.length())          //Found the last index
            {
                end=i;
                while(tIndex>0)             //Optimize the start point by matching backwards.
                {
                    tIndex--;
                    while(S[i]!=T[tIndex])
                        i--;
                    i--;
                }
                i++;    //Set the pointer to the correct position.(Remember this has decresed now since the begining of this if statement.)
                if(end-i+1<result)
                    result=end-i+1,s=i;
            }
        }
        return result==INT_MAX?"":S.substr(s,result);
    }
};