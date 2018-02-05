class Solution {
public:
    string getPermutation(int n, int k)
    {
        string result;
        vector<int> numbers,fact;
        numbers.reserve(9),fact.reserve(9);
        fact[0]=1,numbers.push_back(1);
        for(int i=2;i<=n;i++)
            fact[i-1]=i*fact[i-2],numbers.push_back(i);
        int num=0;
        while(1)
        {
            if(k==fact[numbers.size()-1])
            {
                for(int i=numbers.size()-1;i>=0;i--)
                    result+=to_string(numbers[i]);
                return result;
            }
            else if(k>fact[numbers.size()-2])
            {
                num++;
                k-=fact[numbers.size()-2];
            }
            else
            {
                result+=to_string(numbers[num]);
                numbers.erase(numbers.begin()+num);
                num=0;
            } 
        }
    }
};