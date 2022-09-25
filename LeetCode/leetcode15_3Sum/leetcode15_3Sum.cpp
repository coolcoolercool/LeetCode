#include "../../include.h"

/**
 * 题目描述:
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素a，b，c，
 * 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 * <p>
 * 注意：答案中不可以包含重复的三元组。
 * <p>
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * <p>
 * 满足要求的三元组集合为：
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 * <p>
 * 核心思想:
 * 先将数组排序，然后将nums[i]作为第一个加数，从i+1到nums.length-1之间初始化两个指针left，right，
 * 为了避免有重复的情况，当nums[i]==nums[i-1],说明有重复的情况，开始下一个循环。
 * 如果num[i]+num[left]+num[right]>0,说明加多了，让right–，
 * 如果num[i]+num[left]+num[right]<0,说明加少了，让left++，
 * 如果等于0，说明符合条件，将这一组解加到集合中，
 * 这是也应该避免第二个加数和第三个加数重复的情况
 * <p>
 * 使用有序数列的好处是，在枚举和移动指针时值相等的数可以跳过，省去去重部分
 * <p>
 * 时间复杂度为O(n^2)
 * 面试字节考过
 */

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;

		if (nums.size() < 3) {
			return res;
		}
		// 需要先排序
		std::sort(nums.begin(), nums.end());

		int left = 0, right = 0;
		for (int i = 0; i < nums.size(); i++) {
			// 避免 重复的情况
			if (i - 1 >= 0 && nums[i - 1] == nums[i]) continue;

			left = i + 1, right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back(vector<int>{nums[i], nums[left], nums[right]});
					left++,	right--;

					// 避免 重复的情况，注意这里的 left - 1 和 right + 1
					while (left < right && nums[left] == nums[left - 1] ) left++;
					while (left < right && nums[right] == nums[right + 1]) right--;
				} else if (sum > 0) {
					right--;
				} else {  // nums[i] + nums[left] + nums[right] < 0
					left++;
				}
			}
		}

		return res;
	}
};