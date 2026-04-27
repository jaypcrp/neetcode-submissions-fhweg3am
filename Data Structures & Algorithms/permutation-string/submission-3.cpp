/* Optimized approach: 
    1. store the frequencies of to check (template string) into one vector.
    2. Compare each character of to be checked string with its frequency (if it is greater then 0 or not (ultimately we are checking its presence))
    3. manage window size --> check the difference between left and right pointers if their difference is greater than the length of the s1.
    4. if it becomes greater then 
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) return false;

        vector<int> freq(26, 0);

        for(char c : s1) {
            freq[c - 'a']++;
        }

        int left = 0;
        int right = 0;
        int required = s1.length();

        while(right < s2.length()) {

            // include current character
            if(freq[s2[right] - 'a'] > 0) {
                required--;
            }
            freq[s2[right] - 'a']--;

            right++;

            // maintain window size
            if(right - left > s1.length()) {
                if(freq[s2[left] - 'a'] >= 0) {
                    required++;
                }
                freq[s2[left] - 'a']++;
                left++;
            }

            // check match
            if(required == 0) {
                return true;
            }
        }

        return false;
    }
};
