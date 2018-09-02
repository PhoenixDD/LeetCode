class Solution {
public:
    vector<string> result;
    string temp_res,temp_str;
    int t;
    void addOperators(string &num,int pos,long curval,long last)
    {
        if(pos==num.length()&&curval==t)
        {
            result.push_back(temp_res);
            return;
        }
        if(pos==num.length()||curval>INT_MAX||curval<INT_MIN)
            return;
        long temp_num;
        for(int i=pos;i<num.length();i++)
        {
            temp_str=num.substr(pos,i-pos+1);
            temp_num=stol(temp_str);
            temp_res+="+",temp_res+=temp_str;
            addOperators(num,i+1,curval+temp_num,temp_num);
            temp_res[temp_res.length()-1-(i-pos+1)]='-';
            addOperators(num,i+1,curval-temp_num,-temp_num);
            temp_res[temp_res.length()-1-(i-pos+1)]='*';
            addOperators(num,i+1,curval-last+last*temp_num,last*temp_num);
            temp_res.erase(temp_res.end()-i+pos-2,temp_res.end());
            if(num[pos]=='0'||temp_num>INT_MAX)
                break;
        }
    }
    vector<string> addOperators(string num, int target) 
    {
        if(num.empty())
            return {};
        long temp_num;
        t=target;
        temp_res.reserve(num.length()+num.length());
        result.reserve(1000);
        for(int i=0;i<num.length();i++)
        {
            temp_res=num.substr(0,i+1);
            temp_num=stol(temp_res);
            addOperators(num,i+1,temp_num,temp_num);
            if(num[0]=='0')
                break;
            temp_res="";
        }
        return result;
    }
    
};