class StringIterator {
public:
    StringIterator(string compressedString)
    {
        compStr=move(compressedString);
        i=0;
        temp=i+1;
        while(temp<compStr.length()&&isdigit(compStr[temp]))
            temp++;
        count=stoi(compStr.substr(i+1,temp-i-1));
    }
    
    char next() 
    {
        if(count>1)
        {
            count--;
            return compStr[i];
        }
        else if(count==1)
        {
            tempChar=compStr[i];
            i++;
            while(i<compStr.length()&&isdigit(compStr[i]))
                i++;
            temp=i+1,count=0;
            while(temp<compStr.length()&&isdigit(compStr[temp]))
                count=count*10+compStr[temp]-'0',temp++;
            return tempChar;
        }
        return ' ';
    }
    
    bool hasNext() 
    {
        return i<compStr.length();
    }
    private:
    string compStr;
    int count,i,temp;
    char tempChar;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */