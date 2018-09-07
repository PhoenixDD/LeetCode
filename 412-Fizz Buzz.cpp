class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> result;
        result.reserve(n);
        string temp;
        for(int i=1;i<=n;i++)
        {
            temp="";
            if(i%3==0)
                temp="Fizz";
            if(i%5==0)
                temp+="Buzz";
            if(temp.empty())
                result.push_back(to_string(i));
            else
                result.push_back(temp);
        }
        return result;
    }
};