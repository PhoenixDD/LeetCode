class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if(!map.count(val))
        {
            map[val]=elements.size();
            elements.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if(map.count(val))
        {
            if(map[val]!=elements.size()-1)
            {
                elements[map[val]]=elements.back();
                map[elements.back()]=map[val];
            }
            elements.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        return elements[rand()%elements.size()];
    }
    private:
    vector<int> elements;
    unordered_map<int,int> map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */