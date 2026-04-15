// First(Brute force) approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int count =0;
        // unordered_map<char,int> store;
        for(int i=0;i<s.length();i++)
        {   
            unordered_map<char,int> store;
            count=0;
            for(int j=i;j<s.length();j++)
            {
                if(store[s[j]]>0)
                {
                    break;
                }
                else{
                    store[s[j]]++;
                    count++;
                }
            }
            maxLength=max(maxLength,count);
        }
        return maxLength;
        // for(char c: s)
        // {

        // }
    }
};
