class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) 
    {
        if(map.count(key))
        {
            list<pair<int,unordered_set<string>>>::iterator it=map[key],it2=it;
            it->second.erase(key);
            if(++it2!=l.end()&&it2->first==it->first+1)
                it2->second.insert(key);
            else
                l.insert(it2,{it->first+1,unordered_set<string>()}),(--it2)->second.insert(key);
            map[key]=it2;
            if(it->second.empty())
                l.erase(it);
        }
        else
        {
            if(l.front().first==1)
                l.begin()->second.insert(key);
            else
            {
                l.push_front({1,unordered_set<string>()});
                l.begin()->second.insert(key);
            }
            map[key]=l.begin();
        }
    }
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) 
    {
        if(map.count(key))
        {
            list<pair<int,unordered_set<string>>>::iterator it=map[key],it2=it,it3=it;
            it->second.erase(key);
            if(it->first==1)
                map.erase(key);
            else if(it!=l.begin()&&(--it2)->first==it->first-1)
                it2->second.insert(key),map[key]=it2;
            else
                l.insert(it,{it->first-1,unordered_set<string>()}),(--it)->second.insert(key),map[key]=it;
            if(it3->second.empty())
                l.erase(it3);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() 
    {
        if(map.empty())
            return "";
        return *(l.back().second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() 
    {
        if(map.empty())
            return "";
        return *(l.front().second.begin());
    }
    private:
    list<pair<int,unordered_set<string>>> l;
    unordered_map<string,list<pair<int,unordered_set<string>>>::iterator> map;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */