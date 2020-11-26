/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */
static int INF=2147483647;
class Solution {
public:
    int search(const ArrayReader& reader, int target) 
    {
        int start=0,end=1,mid,temp;
        while(reader.get(end)<target)
            end<<=1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            temp=reader.get(mid);
            if(temp==target)
                return mid;
            else if(temp>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
};