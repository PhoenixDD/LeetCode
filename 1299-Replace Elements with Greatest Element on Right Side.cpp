class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int greatest=-1;
        for(int i=arr.size()-1;i>=0;i--)
            greatest=max(exchange(arr[i],greatest),arr[i]);
        return arr;
    }
};