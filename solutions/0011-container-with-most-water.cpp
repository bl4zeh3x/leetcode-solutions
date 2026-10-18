class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1, best = 0;
        while (left < right) {
            best = max(best, (right - left) * min(height[left], height[right]));
            if (height[left] <= height[right]) ++left;
            else --right;
        }
        return best;
    }
};
