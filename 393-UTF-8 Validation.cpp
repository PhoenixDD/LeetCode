class Solution {
public:
    int bit_4=0xF8,bit_3=0xF0,bit_2=0xE0,check_result=0x80,check_bit=0xC0;
    int which_utf(int &data)
    {
        if((data&bit_4)==bit_3)
            return 4;
        if((data&bit_3)==bit_2)
            return 3;
        if((data&bit_2)==check_bit)
            return 2;
        if((data&check_result)==0)
            return 1;
        return 0;
    }
    bool validUtf8(vector<int>& data) 
    {
        int result;
        for(int i=0;i<data.size();)
        {
            result=which_utf(data[i]);
            if(!result||i+result>data.size())
                return false;
            i++;
            while(--result)
                if((data[i++]&check_bit)!=check_result)
                    return false;
        }
        return true;
    }
};