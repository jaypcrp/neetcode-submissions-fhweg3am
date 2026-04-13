class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid=0;
        int first = 0;
        int last=nums.size()-1; //last=6
        // nums = [0,1,2,3,4,5]
        while(first<=last)
        {
            mid=(first+last)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                first = mid+1;
            }
            else{
                last=mid-1;
            }
        }
        return -1;
    }
};
