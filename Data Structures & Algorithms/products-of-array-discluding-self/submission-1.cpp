class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        
        //Core logic of this approach
        // start calculating prefix from left end for each element and similalrly, calculate suffix from the end till the first. 

        // Build prefix products
        // The loop is started with 1 because to calcualte prefix it needs the prefix's value of previous number , which initially would be 1 , and if it would start with 0, then prefix of -1 would technically not possible.
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] * nums[i-1];

        // Build suffix products
        // Just as same way for prefix, the suffix also starts with n-2 instead of n-1, because in operations it references suffix of further element, for an example n=4, ideally it should start with 3 .. but in that case it would it needs to reference suffix [4] which is not possible , because its not present.
        for (int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] * nums[i+1];

        // Multiply prefix and suffix
        for (int i = 0; i < n; i++)
            output[i] = prefix[i] * suffix[i];

        return output;
    }
};
