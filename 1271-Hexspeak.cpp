static unordered_map<int,char> m={{0,'O'},{1,'I'},{10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'}};
class Solution {
public:
    string toHexspeak(string num) 
    {
        long n=stol(num);
        string result;
        while(n)
        {
            if(!m.count(n%16))
                return "ERROR";
            result+=m[n%16],n/=16;
        }
        reverse(result.begin(),result.end());
        return result;
            
    }
};