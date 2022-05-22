#include "../../include.h"

/*
给定一个n个元素有序的（升序）整型数组nums 和一个目标值target ，写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。
链接：https://leetcode-cn.com/problems/binary-search
 */

class SolutionMethod {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;

			if (nums[mid] < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}

	// 红蓝二分法模板
	// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/
	int search_rb(vector<int>& nums, int target) {
		int size = nums.size();
		int left = -1, right = size;

		while(left + 1 != right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] == target) {
				return mid;
			}

			if(nums[mid] < target) {
				left = mid;
			} else {
				right = mid;
			}
		}

		if(left == -1 || nums[left] != target) {
			return -1;
		}

		return left;
	}

};


int main_0km4() {
	SolutionMethod sol;
	vector<int> nums = {-1,0,3,5,9,12};

	int target = 5;
	int res = sol.search(nums, target);
	cout << res << endl;

	return 0;
}
