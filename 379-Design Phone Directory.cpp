class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        next=0,Max=maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() 
    {
        if(next<Max)
            return next++;
        else if(!recycle.empty())
        {
            int result=*recycle.begin();
            recycle.erase(recycle.begin());
            return result;
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) 
    {
        return number<Max&&(number>=next||recycle.count(number));
    }
    
    /** Recycle or release a number. */
    void release(int number) 
    {
        if(number<next)
            recycle.insert(number);
    }
    private: 
    int Max,next;
    unordered_set<int> recycle;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */