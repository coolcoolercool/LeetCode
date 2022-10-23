/**
 * 给定整数数组 nums 和 整数 k，请返回数组中第 k 个最大的元素。
 */
#include "../../include.h"

class Solution {
public:
	int partition(vector<int>& arr, int left, int right) {
		int temp = rand() % (right - left + 1) + left;
		swap(arr[temp], arr[left]);

		int pivot = left;
		int index = pivot + 1;
		for (int i = index; i <= right; i++) {
			if (arr[i] < arr[pivot]) {
				swap(arr[i], arr[index]);
				index++;
			}
		}
		swap(arr[pivot], arr[index - 1]);
		return index - 1;
	}

	int quickSort(vector<int>& arr, int left, int right, int kth) {
		// 注意这里没有使用 if(left < right )
		int partitionIndex = partition(arr, left, right);
		if (partitionIndex == kth) {
			return arr[partitionIndex];
		} else if(partitionIndex > kth) {  // 如果枢纽值 大于 kth, 第k大值在枢纽值的左边
			return quickSort(arr, left, partitionIndex - 1, kth);
		} else { // 如果枢纽值 小于 kth, 第k大值，在枢纽值的右边
			return quickSort(arr, partitionIndex + 1, right, kth);
		}
	}

	int findKthLargest(vector<int>& nums, int k) {
		return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
	}
};

int main_pl98() {
	vector<int> arr = {1};
	int k = 1;
	Solution sort;
	int res = sort.findKthLargest(arr, k);

	cout << res << endl;

	return 0;
}