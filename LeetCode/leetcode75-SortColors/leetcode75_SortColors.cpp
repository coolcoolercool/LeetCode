// Created by 周子望 on 2021/11/9.

/*
 题目: 颜色分类
 给定一个包含红色、白色和蓝色，一共n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、1 和 2 分别表示红色、白色和蓝色。

 核心思想:
 0 挪到最前面，2 挪到最后面就完事儿了
 注意 2 挪完如果换出来的不是 1，那么指针要回退，因为 0 和 2 都是需要再次移动的
 */

#include "../../include.h"

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}

		int left = 0, right = nums.size() - 1;

		for (int cur_index = 0; cur_index <= right; cur_index++) {
			if (nums[cur_index] == 0) {
				swap(nums[left], nums[cur_index]);
				left++;
			}

			if (nums[cur_index] == 2) {
				swap(nums[right], nums[cur_index]);
				right--;

				// 这一部分很关键，如果curIndex为0或者2，则减一，交由下次处理。直到当前curIndex不为0和2
				if (nums[cur_index] != 1) cur_index--;
			}

			// 如果一开始或者swap后，nums[i] = 1,就直接++了
		}
	}

public:
	void sortColors_1(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}

		int left = 0, right = nums.size() - 1;

		for (int cur_index = 0; cur_index <= right; cur_index++) {
			if (nums[cur_index] == 0) {
				swap(nums[left], nums[cur_index]);
				left++;
			}

			if (nums[cur_index] == 2) {
				swap(nums[right], nums[cur_index]);
				right--;

				// 这一部分很关键，如果curIndex为0或者2，则减一，交由下次处理。直到当前curIndex不为0和2
				if (nums[cur_index] != 1) cur_index--;
			}

			// 如果一开始或者swap后，nums[i] = 1,就直接++了
		}
	}
};

class Solution_Method {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}

		int left_0 = 0, right_2 = nums.size() - 1;
		int cur_index_1 = 0;

		// 这里是根据移动指针的值来分类的，这里的是 <=
		while (cur_index_1 <= right_2) {
			int num = nums[cur_index_1];

			if (num == 2) {
				if (cur_index_1 != right_2) {
					swap(nums[cur_index_1], nums[right_2]);
					right_2--;
				} else {
					break;
				}
			} else if (num == 0) {
				if (cur_index_1 != left_0) {
					swap(nums[cur_index_1], nums[left_0]);
					left_0++;
				} else {
					cur_index_1++;
					left_0++;
				}
			} else if (num == 1) {
				cur_index_1++;
			}
		}
	}
};

int main_0mkjn () {
	Solution_Method sol;
	vector<int> nums;

	nums = {2,0,2,1,1,0};
	sol.sortColors(nums);
	print_vector(nums);

	nums = {2,0,1};
	sol.sortColors(nums);
	print_vector(nums);

	nums = {1,0,2};
	sol.sortColors(nums);
	print_vector(nums);

	nums = {0};
	sol.sortColors(nums);
	print_vector(nums);

	return 0;
}

/*
			if (nums[left] == 2 && nums[right] == 0) {
				swap(nums[left], nums[right]);
				left++;
				right--;
			} else if (nums[left] == 1 && nums[right] == 0) {
				swap(nums[left], nums[right]);
				left++;
				right--;
			} else if (nums[left] == 2 && nums[right] == ) {

			}
 */