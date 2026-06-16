class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++)
        {
            if(count[nums[i]] == 1)
            {
                return nums[i];
            }
            count[nums[i]]++;
        }
    }
};
