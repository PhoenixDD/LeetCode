static unordered_map<string,int> gran={{"Year",0},{"Month",1},{"Day",2},{"Hour",3},{"Minute",4},{"Second",5}};
class LogSystem {
public:
    LogSystem() {
        
    }
    long getKey(string &t,int g)
    {
        stringstream ss(t);
        for(int i=0;i<6;i++)
            getline(ss, token, ':'),timeStamp[i]=stoi(token);
        key=timeStamp[0];
        for(int i=1;i<6;i++)
            if(i<=g)
                key=key*100+timeStamp[i];
            else
                key*=100;
        return key;
    }
    //This loop can be trimmed down and made dynamic.
    long addOne(int g)
    {
        if(g==0)
            return 10000000000;
        if(g==1)
            return 100000000;
        if(g==2)
            return 1000000;
        if(g==3)
            return 10000;
        if(g==4)
            return 100;
        return 1;
    }
    void put(int id, string timestamp) 
    {
        mp[getKey(timestamp,5)]=id;
    }
    
    vector<int> retrieve(string s, string e, string gra)
    {
        it1=mp.lower_bound(getKey(s,gran[gra]));
        end=getKey(e,gran[gra]);
        end+=addOne(gran[gra]);
        vector<int> result;
        while(it1!=mp.end())
            if(it1->first>=end)
                break;
            else
                result.push_back(it1++->second);
        return result;            
    }
    private:
    map<long,int> mp;
    map<long,int>::iterator it1,it2;
    string token;
    long key,end;
    vector<int> timeStamp{vector<int>(6)};
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */