class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() 
    {
        srand(time(NULL));    
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
        bool result=!map.count(val)||map[val].empty();
        map[val].insert(collection.size());
        collection.push_back(val);
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) 
    {
        if(!map.count(val)||map[val].empty())
            return false;
        int index=*map[val].begin();
        map[val].erase(map[val].begin());
        if(index!=collection.size()-1)
        {
            collection[index]=collection.back();
            map[collection.back()].erase(map[collection.back()].find(collection.size()-1));
            map[collection.back()].insert(index);
        }
        collection.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() 
    {
        return collection[rand()%collection.size()];
    }
    private:
    vector<int> collection;
    unordered_map<int,unordered_set<int>> map;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */