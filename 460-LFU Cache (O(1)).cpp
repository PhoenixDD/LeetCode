class LFUCache {
public:
    LFUCache(int capacity) 
    {
        cap=capacity;
    }
    
    int get(int key) 
    {
        if(cache.count(key))
        {
            list<pair<int,list<int>>>::iterator it=cache[key].second.first,it2=it;
            it->second.erase(cache[key].second.second);
            if(++it2!=l.end()&&it2->first==it->first+1)
                it2->second.push_front(key);
            else
                l.insert(it2,{it->first+1,list<int>()}),(--it2)->second.push_front(key);
            cache[key].second={it2,it2->second.begin()};
            if(it->second.empty())
                l.erase(it);
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(!cap)
            return;
        if(cache.count(key))
        {
            list<pair<int,list<int>>>::iterator it=cache[key].second.first,it2=it;
            it->second.erase(cache[key].second.second);
            if(++it2!=l.end()&&it2->first==it->first+1)
                it2->second.push_front(key);
            else
                l.insert(it2,{it->first+1,list<int>()}),(--it2)->second.push_front(key);
            cache[key]={value,{it2,it2->second.begin()}};
            if(it->second.empty())
                l.erase(it);
            return;
        }
        else if(cap==cache.size())
        {
            cache.erase(l.front().second.back());
            l.front().second.pop_back();
            if(l.front().second.empty())
                l.pop_front();
        }
        if(l.front().first!=1)
            l.push_front({1,list<int>()});
        l.front().second.push_front(key);
        cache[key]={value,{l.begin(),l.front().second.begin()}};
    }
    private:
    int cap;
    list<pair<int,list<int>>> l;
    unordered_map<int,pair<int,pair<list<pair<int,list<int>>>::iterator,list<int>::iterator>>> cache;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */