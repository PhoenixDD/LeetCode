class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(num.length()==k)
            return "0";
        string result;
        result.reserve(num.size()-k);
        int i=0;
        result+=num[i++];
        while(k&&i<num.size())
        {
            while(!result.empty()&&result.back()>num[i]&&k)
                result.pop_back(),k--;
            result+=num[i++];
            if(!result.empty()&&result.front()=='0')
                result.pop_back();
        }
        result.insert(result.end(),num.begin()+i,num.end());
        while(k--)
            result.pop_back();
        return result.empty()?"0":result;
        
    }
};