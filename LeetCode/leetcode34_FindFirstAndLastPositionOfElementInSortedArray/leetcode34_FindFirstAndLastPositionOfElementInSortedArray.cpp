#include "../../include.h"

/*
题目:
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回[-1, -1]。

进阶：
你可以设计并实现时间复杂度为O(log n)的算法解决此问题吗？
 
思路:
 二分用这个模板就不会出错了。
 满足条件的都写l = mid或者r = mid，mid首先写成l + r >> 1，

 如果满足条件选择的是l = mid，那么mid那里就加个1，写成l + r + 1 >> 1。

 然后就是else对应的写法l = mid 对应 r = mid - 1，r = mid 对应 l = mid + 1

 用这个
 1、满足条件写 right = mid，else 写left = mid + 1，在取mid的时候，写成 mid = (left + right) / 2，
 2、满足条件写 left = mid，else 写right = mid - 1, 在取mid的时候，写成 mid = (left + right + 1) / 2，


 为什么取左边第一个等于target的要用模板1，取最后一个等于target的要用模板2
 取左边第一个target时，当nums[mid]==target时，中间位置的右边元素一定不是target出现的第一个位置，所以下次搜索区间是[left,mid],right=mid;取最后一个target时，当nums[mid]==target时，中间位置的左边元素一定不是target出现的最后一个位置，所以下次搜索区间是[mid，right],left=mid;
 */

class Solution {
public:
	vector<int> searchRange(vector<int> &nums, int target) {
		vector<int> res = {-1, -1};

		int size = nums.size();
		// 数组为空，或者target不在有序数组的范围内，均直接返回 -1,-1
		if (nums.empty() || target < nums[0] || target > nums[size - 1]) {
			return res;
		}

		// 找target的左边界
		int left = 0, right = size - 1;
		while (left < right) {  // 这里 left 不是 <= right，避免了下面的right = mid的死循环
			int mid = (left + right) / 2;

			if (nums[mid] >= target) { // 左边界，每次划分，倾向左边，使用right达到左边界
				right = mid;
			} else { // {mid + 1, right}
				left = mid + 1;
			}
		}

		if (nums[right] != target) {
			return res;
		}
		res[0] = right;

		// 找target的右边界
		left = 0, right = size - 1;
		while (left < right) {
			int mid = (left + right + 1) / 2; // 这里是差异的重点

			if (nums[mid] <= target) { // 因为要找有边界，每次倾右边，
				left = mid;
			} else {
				right = mid - 1;
			}
		}

		res[1] = right;

		return res;
	}
};

int main_9ngf3() {
	Solution sol;
	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;
	vector<int> res = sol.searchRange(nums, target);
	cout << res[0] << ", " << res[1] << endl;

	return 0;
}

