#include <algorithm>
#include "../../include.h"

/*
核心思想:
 注意到下一个排列总是比当前排列要大，除非该排列已经是最大的排列。我们希望找到一种方法，能够找到一个大于当前序列的新序列，且变大的幅度尽可能小。具体地：
我们需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
同时我们要让这个「较小数」尽量靠右，而「较大数」尽可能小。当交换完成后，「较大数」右边的数需要按照升序重新排列。这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。

以排列 [4,5,2,6,3,1] 为例：
我们能找到的符合条件的一对「较小数」与「较大数」的组合为 2 与 3，满足「较小数」尽量靠右，而「较大数」尽可能小
当我们完成交换后排列变为 [4,5,3,6,2,1]，此时我们可以重排「较小数」右边的序列，序列变为 [4,5,3,1,2,6]。

具体地，我们这样描述该算法，对于长度为 n 的排列 a：
首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 j 满足 a[i] < a[j]。这样「较大数」即为 a[j]。
交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。

 注意
如果在步骤 1 找不到顺序对，说明当前序列已经是一个降序序列，即最大的序列，我们直接跳过步骤 2 执行步骤 3，即可得到最小的升序序列。
该方法支持序列中存在重复元素，且在 C++ 的标准库函数 next_permutation 中被采用。
 */

class Solution {
public:
	/**
		手动实现 时间复杂度O(n),空间复杂度O(1)
		从后往前找到第一个【相邻升序对】，即A[i]<A[i+1]。此时A[i+1,end)为降序。
		在区间[i+1,end)中，从后往前找到第一个大于A[i]的元素A[j]
		交换A[i]和A[j]，此时A[i+1,end)一定还是降序，因为A[j]是从右侧起第一个大于A[i]的值
		反转A[i+1,end)，变成升序
		应用场景：可兼容处理含有重复元素的全排列问题
            0 1 2 3 4 5
	 	eg. 1 8 5 7 6 4
	 	i = 2 对应值为5
	 	j = 4 对应值为6

	 	交换 i 与 j
	 	-> 1 8 6 7 5 4

	 	逆序 i + 1, end()
	 	-> 1 8 6 4 5 7

	 */
	void nextPermutation(vector<int> &nums) {
		int i = 0;
		for (i = nums.size() - 2; i >= 0; i--) { // 从后往前找到第一个相邻升序对
			if (nums[i] < nums[i + 1]) break;
		}

		if (i == -1) {
			reverse(nums.begin(), nums.end()); // 无相邻升序对，必定为非递减序列
		} else {
			for (int j = nums.size() - 1; j >= i + 1; --j) { // 从后往前[i+1,end)找第一个大于a[i+1]的值
				if (nums[i] < nums[j]) {
					swap(nums[i], nums[j]); // 交换二者
					reverse(nums.begin() + i + 1, nums.end()); // 反转[i+1,end)，变成升序
					break;
				}
			}
		}
	}

public:
	void nextPermutation_1(vector<int>& nums) {
		// 从右向左找，第一个 nums[i] < nums[i + 1] 的 非降序的nums[i]
		int i = nums.size() - 2;
		while (i > 0 && nums[i] >= nums[i + 1]) {
			i--;
		}

		if (i >= 0) { // 如果i小于0，表示已经排序组合中的最大值了
			// 从右向左找，第一个 比 nums[i]大的nums[j]，然后交换nums[i]和nums[j]
			int j = nums.size() - 1;
			while (j >= 0 && nums[j] <= nums[i]) {
				j--;
			}
			swap(nums[i], nums[j]);
		}

		reverse(nums.begin() + i + 1, nums.end());  // 重新升序排列，i+1 ～ nums.size() - 1 的元素，达到最小值的目标
	}
};
