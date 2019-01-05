/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        its.push_back(nestedList.begin());                          //We insert the iterator even if the list is empty and check later
        end=nestedList.end();                                       //Store the end of the main list
        point_to_int();
    }
    int next() 
    {
        int next=its.back()->getInteger();
        its.back()++;                                           //Increment iterator.
        point_to_int();
        return next;
    }
    void point_to_int()                                           //make the top iterator point to an integer
    {
        while(its.size()>1&&its.back()==its[its.size()-2]->getList().end()) //for cases where top iterator is end of that list eg:[[1],1]
            its.pop_back(),its.back()++;
        while(hasNext()&&!its.back()->isInteger())                          //Until the top iterator is integer or main list is exhausted
        {
            its.push_back(its.back()->getList().begin());                   //push the next list's begining iterator.
            point_to_int();                                                 //Keep repeating 2 while loops until integer found.
        }
    }
    bool hasNext()
    {
        return !(its.size()==1&&its.back()==end);             //if its.size is 1 (i.e main list) and the iterator points to end (main list)
    }
    private:
    vector<vector<NestedInteger>::iterator> its;   //We use vector instead of stack because we need second last iterator which is parent.
    vector<NestedInteger>::iterator end;            //Store end of main list.
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */