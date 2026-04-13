class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for(int i=1;i<=numbers.size();i++)
        {
            for(int j=i+1;j<=numbers.size();j++)
            {
                if(target==numbers[i-1]+numbers[j-1])
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
                else{
                    continue;
                }
            }
        }
        return result;
    }
};
