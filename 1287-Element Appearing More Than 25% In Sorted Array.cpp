class Solution {
public:
    bool isRes(vector<int> &arr,int i)
    {
        int start=lower_bound(arr.begin(),arr.end(),arr[i])-arr.begin(),end=upper_bound(arr.begin()+start,arr.end(),arr[i])-arr.begin();
        return end-start>arr.size()/4;
    }
    int findSpecialInteger(vector<int>& arr) 
    {
        vector<int> toCheck={arr.size()/4,arr.size()/2,(arr.size()*3)/4};
        for(int &i:toCheck)
        if(isRes(arr,i))
            return arr[i];
        return -1;
    }
};