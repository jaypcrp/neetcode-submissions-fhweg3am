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
            for(int i =0; i<nums.size();i++)
            {
                if(count[nums[i]]>max)
                {
                    max=count[nums[i]];
                    maxElement = nums[i];
                }
                else{
                    continue;
                }
            }
            count[nums[maxElement]]=-1;
            result.push_back(maxElement);
        }
        return result;
    }
};
//         //
//         //
//         //
//         for(int i=0;i<nums.size();i++)
//         {
//             if (i == 0 && count[nums[i]]>=max)
//                 {
//                     result.push_back(count[nums[i]]);
//                     max=count[nums[i]];
//                 }
//             for(int j=0;j<=result.back();j++)
//             {
//                 if(count[nums[j]]<count[nums[i]])
//                 {
//                     result.insert
//                 }
//             }
//             if (i == 0 && count[nums[i]]>=max)
//             {
//                 result.push_back(count[nums[i]]);
//                 max=count[nums[i]];
//             }
//             else if(count[nums[i]])
//             else if(result[i-1]>count[nums[i]] && count[nums[i]]>max)
//             {
//                 result.insert(i-1)
//             }
//             else if()
//         }
//         for(int i=0;i<k;i++)
//         {
//             result.push_back(max[i]);
//         }
//         return result;
//     }
// };
