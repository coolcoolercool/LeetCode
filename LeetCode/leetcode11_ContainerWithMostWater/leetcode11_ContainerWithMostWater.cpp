#include "../../include.h"
/**


1204
 */

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxArea = 0;

		int left = 0, right = height.size() - 1;
		while (left < right) {
			int area = (right - left) * min(height[left], height[right]);
			maxArea = max(maxArea, area);
			// 移动高度大的柱子，面积一定会减少，移动高度小的柱子，面积变化不定
			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return maxArea;
	}
};











