class FileSystem {
public:
    FileSystem() 
    {
        paths[""]=-1;
    }
    
    bool create(string path, int value) 
    {
        if(paths.count(path.substr(0,path.find_last_of('/'))))
        {
            paths[path]=value;
            return true;
        }
        return false;
    }
    
    int get(string path) 
    {
        it=paths.find(path);
        if(it!=paths.end())
            return it->second;
        return -1;
    }
    private:
    unordered_map<string,int> paths;
    unordered_map<string,int>::iterator it;
    string temp;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */