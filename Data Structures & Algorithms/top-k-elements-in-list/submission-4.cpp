class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        int max=0;
        int maxElement=0;
        // int n  = nums.size();
        // vector<int> count = (n;
        // int max=0;
        unordered_map<int,int> count;
        for(int i=0; i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        for(int j =0;j<k;j++)
        {
            max=0;
            for(int i =0; i<nums.size();i++)
            {
                if(count[nums[i]]>=max)
                {
                    max=count[nums[i]];
                    maxElement = nums[i];
                }
                else{
                    continue;
                }
            }
            count[maxElement]=-1;
            result.push_back(maxElement);
        }
        return result;
    }
};
