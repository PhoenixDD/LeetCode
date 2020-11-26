class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) 
    {
        itBegin=v.begin(),itEnd=v.end();
        while(itBegin!=itEnd)
        {
            itCurrBegin=itBegin->begin(),itCurrEnd=itBegin->end();
            if(itCurrBegin!=itCurrEnd)
                break;
            itBegin++;
        }
            
    }
    
    int next() 
    {
        int result=*itCurrBegin++;
        while(itCurrBegin==itCurrEnd&&++itBegin!=itEnd)
            itCurrBegin=itBegin->begin(),itCurrEnd=itBegin->end();
        return result;
    }
    
    bool hasNext() 
    {
        return itEnd!=itBegin;
    }
    private:
    vector<vector<int>>::iterator itBegin,itEnd;
    vector<int>::iterator itCurrBegin,itCurrEnd;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */