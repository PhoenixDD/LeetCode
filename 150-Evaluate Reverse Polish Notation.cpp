class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        int a,b,op;
        stack<int> s;
        unordered_map<string,int> map={{"+",1},{"-",2},{"*",3},{"/",4}};
        for(string &t:tokens)
        {
            op=map[t];
            switch(op)
            {
                case 1:   b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a+b);break;
                case 2:   b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a-b);break;
                case 3:   b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a*b);break;
                case 4:   b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a/b);break;
                default:  s.push(stoi(t));
            }
        }
        return s.top();
    }
};