class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid;
        int first = 0;
        int last=nums.size(); //last=6
        // nums = [0,1,2,3,4,5]
        while(mid!=0)
        {
            mid=(first+last)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                first = mid;
            }
            else{
                last=mid;
            }
        }
        return mid;
    }
};
