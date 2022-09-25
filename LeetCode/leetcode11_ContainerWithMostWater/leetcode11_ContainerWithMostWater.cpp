#include "../../include.h"

class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_area = 0;

		int left = 0, right = height.size() - 1;
		while (left < right) {
			int area = (right - left) * min(height[left], height[right]);
			max_area = max(max_area, area);
			// 移动高度大的柱子，面积一定会减少，移动高度小的柱子，面积变化不定
			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return max_area;
	}
};











