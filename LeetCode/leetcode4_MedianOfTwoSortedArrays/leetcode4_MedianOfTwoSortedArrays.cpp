#include "../../include.h"

/*
题目描述:
 给定两个大小分别为 m 和 n 的正序（从小到大）数组nums1 和nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

在统计中，中位数被用来：
将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。

 核心思想:
要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
 * 这里的 "/" 表示整除
 * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
 * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
 * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
 * 这样 pivot 本身最大也只能是第 k-1 小的元素
 * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
 * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
 * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数

这个解答很好
https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/

 */

class Solution {
	//
public:
	int getKthElem(vector<int> &leftVec, vector<int> &rightVec, int k) {
		int leftSize = leftVec.size();
		int rightSize = rightVec.size();

		int curLeft = 0, curRight = 0;
		int newIndexLeft = 0, newIndexRight = 0;
		while (true) {
			// 递归终止条件，主要是不断的缩减k的值，最后可能会是三种情况，left数组到头了，right数组到头了，k到1无法再缩减
			if (curLeft == leftSize) return rightVec[curRight + k - 1];
			if (curRight == rightSize) return leftVec[curLeft + k - 1];
			if (k == 1) return min(leftVec[curLeft], rightVec[curRight]);

			newIndexLeft = min(curLeft + k / 2 - 1, leftSize - 1);
			newIndexRight = min(curRight + k / 2 - 1, rightSize - 1);

			if (leftVec[newIndexLeft] <= rightVec[newIndexRight]) {
				k -= newIndexLeft - curLeft + 1; // 如果left小，则说明 curLeft ~ newIndexLeft 都不会是两个数组的第K大的数。那么此时就可以在newIndexLeft + 1和curRight上继续寻找，此时k缩小了 newIndexLeft - curLeft + 1 = curRight + k/2 - 1 - curLeft + 1 = k/2
				curLeft = newIndexLeft + 1;
			} else {
				k -= newIndexRight - curRight + 1; // 如果right 小，则说明 curRight ~ newIndexRight 都不会是两个数组的第K大的数
				curRight = newIndexRight + 1;
			}
		}
	}

	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		int totalLen = len1 + len2;

		if (totalLen % 2 == 1) {  // 奇数的中位数
			return double(getKthElem(nums1, nums2, (totalLen + 1) / 2));
		} else {
			return double(getKthElem(nums1, nums2, totalLen / 2) + getKthElem(nums1, nums2, totalLen / 2 + 1)) / 2.0;
		}
	}


public:
	// 先将两个数组合并，两个有序数组的合并也是归并排序中的一部分。然后根据奇数，还是偶数，返回中位数。
	double findMedianSortedArrays_merge(vector<int>& nums1, vector<int>& nums2) {
		int leftSize = nums1.size();
		int rightSize = nums2.size();
		int totalSize = leftSize + rightSize;
		int pre = -1, cur = -1;
		int leftIndex = 0, rightIndex = 0;
		for (int i = 0; i <= totalSize / 2; i++) {
			pre = cur;
			if (leftIndex < leftSize && (rightIndex >= rightSize || nums1[leftIndex] < nums2[rightIndex])) {
				cur = nums1[leftIndex++];
			} else {
				cur = nums2[rightIndex++];
			}
		}
		if ((totalSize & 1) == 0)
			return (pre + cur) / 2.0;
		else
			return cur;
	}
};