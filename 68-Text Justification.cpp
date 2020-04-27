class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        int index=0,curLength,numWords,prevIndex,spaces,plusOneSpaces;
        vector<string> result;
        while(index<words.size())
        {
            curLength=0,numWords=0,prevIndex=index;
            while(index<words.size()&&curLength+numWords+words[index].length()<=maxWidth)
            {
                curLength+=words[index++].length();
                numWords++;
            }
            result.push_back("");
            spaces=(maxWidth-curLength)/(numWords==1?1:numWords-1);
            plusOneSpaces=(maxWidth-curLength)%(numWords==1?1:numWords-1);
            if(index<words.size())
            {
                while(prevIndex!=index)
                {
                    result.back()+=words[prevIndex++];
                    if(prevIndex<index||numWords==1)
                        result.back()+=string(spaces+(plusOneSpaces-->0),' ');
                }
            }
            else
            {
                while(prevIndex!=index)
                {
                    result.back()+=words[prevIndex++];
                    if(prevIndex<index)
                        result.back()+=" ";
                }
                if(maxWidth-curLength-numWords+1>0)
                    result.back()+=string(maxWidth-curLength-numWords+1,' ');
            }
        }
        return result;
    }
};