class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int n = height.size();
        int right = n - 1;

        int finalArea = 0;

        while(left < right)
        {
            int width = right - left;
            int currHeight = min(height[left], height[right]);
            int currArea = width * currHeight;
            finalArea = max(currArea, finalArea);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return finalArea;

    }
};