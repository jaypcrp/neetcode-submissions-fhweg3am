//  brute force approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Step 1: Find the candidate row
        // We want the largest row index where matrix[row][0] <= target
        int top = 0, bot = m - 1;
        int row = -1;
        while (top <= bot) {
            int mid = top + (bot - top) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) {
                row = mid;          // candidate, try going right
                top = mid + 1;
            } else {
                bot = mid - 1;
            }
        }
        if (row == -1) return false;   // target smaller than every row's first
        
        // Step 2: Binary search inside that row
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};