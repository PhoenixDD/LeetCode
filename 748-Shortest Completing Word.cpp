static vector<int> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        long licensePlateHash=1;
        int resultIndex=-1;
        for(char &c:licensePlate)
            if(isalpha(c))
                licensePlateHash*=primes[tolower(c)-'a'];
        for(int i=0;i<words.size();i++)
        {
            long result=1;
            for(char &c:words[i])
                result=(result*primes[c-'a'])%licensePlateHash;
            cout<<resultIndex<<endl;
            if(!result&&(resultIndex==-1||words[resultIndex].length()>words[i].length()))
                resultIndex=i;
        } 
        return words[resultIndex];
    }
};