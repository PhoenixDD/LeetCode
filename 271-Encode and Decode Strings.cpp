//Reserve a few bytes to put the length of the string.
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) 
    {
        string result,len;
        for(string &s:strs)
        {
            len=to_string(s.length());
            len=string(4-len.length(),'0')+len;
            result+=len+s;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> result;
        int i=0,len;
        while(i<s.length())
        {
            len=(s[i]-'0')*1000+(s[i+1]-'0')*100+(s[i+2]-'0')*10+(s[i+3]-'0');
            i+=4;
            result.push_back(s.substr(i,len));
            i+=len;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));