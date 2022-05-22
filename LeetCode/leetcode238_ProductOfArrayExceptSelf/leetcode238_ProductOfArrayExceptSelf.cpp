// Created by rainyzwzhou on 2022/5/12.

#include <bits/stdc++.h>

using namespace std;

class Solution {
	/**
	 * 基于使用 left 和 right 的思想来的，只不过将left 和 right都在 res中实现
	 */
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		vector<int> res(size);

		// res[i] 表示索引 i 左侧所有元素的乘积
		// 因为索引为 '0' 的元素左侧没有元素， 所以 res[0] = 1
		res[0] = 1;
		for (int i = 1; i < size; i++) {
			res[i] = nums[i - 1] * res[i - 1];
		}

		// right 为右侧所有元素的乘积
		// 刚开始右边没有元素，所以 right = 1
		int right = 1;
		for (int i = size - 1; i >= 0; i--) {
			// 对于索引 i，左边的乘积为 res[i]，右边的乘积为 right
			res[i] = res[i] * right;
			// right 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 right 上
			right *= nums[i];
		}

		return res;
	}

public:
	/**
	 * 利用索引左侧所有数字的乘积和右侧所有数字的乘积（即前缀与后缀）相乘得到答案。
		对于给定索引 ii，我们将使用它左边所有数字的乘积乘以右边所有数字的乘积
	 * @param nums
	 * @return
	 */
	vector<int> productExceptSelf_ver0(vector<int>& nums) {
		int size = nums.size();

		// left 和 right 分别表示左右两侧的乘积列表
		vector<int> left(size, 0), right(size, 0);

		vector<int> res(size);
		// left[i] 为索引 i 左侧所有元素的乘积
		// 对于索引为 '0' 的元素，因为左侧没有元素，所以 left[0] = 1
		left[0] = 1;
		for(int i = 1; i < size; i++) {
			left[i] = nums[i - 1] * left[i - 1];
		}

		// right[i] 为索引 i 右侧所有元素的乘积
		// 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 right[length-1] = 1
		right[size - 1] = 1;
		for(int i = size - 2; i >= 0; i--) {
			right[i] = nums[i + 1] * right[i + 1];
		}

		// 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
		for(int i = 0; i < size; i++) {
			res[i] = left[i] * right[i];
		}

		return res;
	}
};
