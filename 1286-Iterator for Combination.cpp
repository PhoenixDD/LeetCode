class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) 
    {
        chars=characters;
        K=combinationLength;
        temp.resize(K);
        select(0,0);
        i=0;
    }
    void select(int i,int k)
    {
        if(k==K)
        {
            result.push_back(temp);
            return;
        }
        else if(i==chars.length())
            return;
        temp[k]=chars[i];
        select(i+1,k+1);
        select(i+1,k);
    }
    string next() 
    {
        return result[i++];
    }
    
    bool hasNext() 
    {
        return i<result.size();
    }
    private:
    string chars;
    vector<string> result;
    string temp;
    int K,i;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */