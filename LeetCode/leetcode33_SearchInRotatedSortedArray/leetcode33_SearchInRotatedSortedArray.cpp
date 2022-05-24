#include "../../include.h"

/*
在常规二分查找的时候查看当前 mid 为分割位置分割出来的两个部分 [l, mid] 和 [mid + 1, r] 哪个部分是有序的，
并根据有序的那个部分确定我们该如何改变二分查找的上下界，因为我们能够根据有序的那部分判断出 target 在不在这个部分：

 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
 */

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int mid = 0;

		if (nums.empty()) return -1;

		while (left <= right) {
			mid = left + (right - left) / 2;

			if (nums[mid] == target) return mid;
			else if (nums[left] == target) return left;
			else if (nums[right] == target) return right;

			// 先判断那边有序
			// mid ～ right 有序
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target && nums[right] > target) { // 在 mid + 1 ~ right
					left = mid + 1;
				} else {    // 在 left ～ mid - 1
					right = mid - 1;
				}
			} else { // left ~ mid 有序  这里else 是包含 nums[mid] >= nums[right], 可能会重合
				if (nums[left] < target && nums[mid] > target) { // 在 left ～ mid - 1
					right = mid - 1;
				} else {   // 在 mid + 1 ～ right
					left = mid + 1;
				}
			}
		}
		return -1;
	}
};

// Test
int main_asdf9()
{
	Solution sol;
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int target = 0;
	int res = sol.search(nums, target);
	cout << res << endl;

	nums = {4,5,6,7,0,1};
	target = 3;
	res = sol.search(nums, target);
	cout << res << endl;

	nums = {1};
	target = 0;
	res = sol.search(nums, target);
	cout << res << endl;

	nums = {1};
	target = 1;
	res = sol.search(nums, target);
	cout << res << endl;

	nums = {5,1,2,3,4};
	target = 1;
	res = sol.search(nums, target);
	cout << res << endl;

	return 0;
}

