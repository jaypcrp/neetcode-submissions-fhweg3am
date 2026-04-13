class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end()); 
                        if (find(result.begin(), result.end(), temp) != result.end()) 
                        {
                            return result;
                        }
                        else{
                            result.push_back({nums[i],nums[j],nums[k]});
                        }
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return result;
    }
};
