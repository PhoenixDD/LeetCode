class Solution {
public:
    string temp;
    vector<string> result;
    void bt(string &w,int start,bool canSelect)
    {
        if(start==w.length())
        {
            result.push_back(temp);
            return;
        }
        temp+=w[start];
        bt(w,start+1,true);
        temp.pop_back();
        int tempLength=temp.size();
        if(canSelect)
            for(int i=start;i<w.length();i++)
            {
                temp+=to_string(i-start+1);
                bt(w,i+1,false);
                temp.erase(temp.begin()+tempLength,temp.end());
            }
    }
    vector<string> generateAbbreviations(string word) 
    {
        bt(word,0,true);
        return result;
    }
};