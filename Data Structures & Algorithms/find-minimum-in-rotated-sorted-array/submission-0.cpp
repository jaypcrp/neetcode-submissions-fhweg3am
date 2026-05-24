// Optimized approach 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right])
                left = mid + 1;   // rotation point is right of mid
            else
                right = mid;      // mid is a candidate for minimum
        }
        
        return nums[left];
    }
};
