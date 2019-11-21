class Solution {
public:
    vector<int> transformArray(vector<int>& arr) 
    {
        bool changed=true;
        int prev;
        while(changed)
        {
            changed=false;
            prev=arr.front();
            for(int i=1;i<arr.size()-1;i++)
            {
                if(arr[i]>prev&&arr[i]>arr[i+1])
                    prev=arr[i],changed=true,arr[i]--;
                else if(arr[i]<prev&&arr[i]<arr[i+1])
                    prev=arr[i],changed=true,arr[i]++;
                else
                    prev=arr[i];
            }
        }
        return arr;
    }
};