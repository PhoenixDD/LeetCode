static vector<int> shortHands={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
class Solution {
public:
    int toInt(string s)
    {
        return 16*(isdigit(s.front())?(s.front()-'0'):(s.front()-'a'+10))+(isdigit(s.back())?(s.back()-'0'):(s.back()-'a'+10));
    }
    string toHex(int i)
    {
        string result(2,' ');
        result.back()=(i%16)<10?(i%16)+'0':(i%16)-10+'a';
        i/=16;
        result.front()=(i%16)<10?(i%16)+'0':(i%16)-10+'a';
        return result;
    }
    int getClosest(int i)
    {
        int dist=INT_MAX,result;
        for(int &x:shortHands)
            if(abs(x-i)<dist)
                dist=abs(x-i),result=x;
        return result;
    }
    string similarRGB(string color) 
    {
        return "#"+toHex(getClosest(toInt(color.substr(1,2))))+toHex(getClosest(toInt(color.substr(3,2))))+toHex(getClosest(toInt(color.substr(5,2))));
    }
};