class LRUCache {
public:
    LRUCache(int capacity):cap(capacity)
    {
    }
    
    int get(int key) 
    {
        if(cache.count(key))
        {
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second=order.begin();
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(cache.count(key))
            order.erase(cache[key].second);
        else if(cap==cache.size())
            cache.erase(order.back()),order.pop_back();
        order.push_front(key);
        cache[key]={value,order.begin()};
    }
    private:
    int cap;
    list<int> order;
    unordered_map<int,pair<int,list<int>::iterator>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */