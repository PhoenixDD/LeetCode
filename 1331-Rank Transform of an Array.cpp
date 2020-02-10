class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        if(arr.empty())
            return {};
        vector<pair<int,int>> index(arr.size());
        for(int i=0;i<arr.size();i++)
            index[i]={arr[i],i};
        sort(index.begin(),index.end(),[](pair<int,int>&l,pair<int,int>&r){return l.first<r.first;});
        arr[index.front().second]=1;
        for(int i=1,j=1;i<index.size();i++)
            j+=index[i].first!=index[i-1].first,arr[index[i].second]=j;
        return arr;
    }
};