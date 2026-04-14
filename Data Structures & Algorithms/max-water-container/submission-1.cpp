//1st Attempt-My approach(brute force)
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left =0;
        int right = heights.size()-1;
        int area=0;
        while(left<right)
        {
            if(heights[left]<heights[right])
            {
                area=(right-left)*heights[left];
                left++;
                if(area>maxArea)
                {
                    maxArea=area;
                }
            }
            else{
                area=(right-left)*heights[right];
                right--;
                if(area>maxArea)
                {
                    maxArea=area;
                }
            }
        }
        return maxArea;
    }
};
