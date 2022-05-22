// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:

核心思想:
 我们将给定的数组 nums 表示为三段子数组拼接的形式，分别记作 numsLeft, numsMid, numsRight,
 其中left和right是已经有序的了，需要对 numMid 排序，才能让 nums 有序

  一次遍历
  正常排序(1 2 3 4 5): 左边所有元素的最大值(2) <= 每个元素(例如3) <= 右边所有元素的最小值(4)
  求解: 2  6  8  10  4  9  15
  其中: 从左到右 9是最后一个小于 (左边所有元素最大值)的
  从右到左 6是最后一个大于 (右边所有元素最小值)的
 	故解为求:
  	从左到右遍历, 记录当前遍历数的最大值, 最后一个小于最大值的即 需要倒置数组的右边索引
  	从右到左遍历, 记录当前遍历数的最小值, 最后一个大于最小值的即 需要倒置数组的左边索引


 一种解读思路:
 先只考虑中段数组，设其左边界为L，右边界为R：
	nums[R] 不可能是【L，R】中的最大值（否则应该将 nums[R] 并入右端数组）
	nums[L] 不可能是【L，R】中的最小值（否则应该将 nums[L] 并入左端数组）

  很明显:
	【L，R】中的最大值 等于【0，R】中的最大值，设其为 max
	【L，R】中的最小值 等于 【L， nums.length-1】中的最小值，设其为 min
	那么有：
	nums[R] < max < nums[R+1] < nums[R+2] < ... 所以说，从左往右遍历，最后一个小于max的为右边界
	nums[L] > min > nums[L-1] > nums[L-2] > ... 所以说，从右往左遍历，最后一个大于min的为左边界

 * */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	// https://pic.leetcode-cn.com/1627957087-VYaluV-%E6%9C%80%E7%9F%AD%E6%97%A0%E5%BA%8F%E8%BF%9E%E7%BB%AD%E5%AD%90%E6%95%B0%E7%BB%84%E9%A2%98%E8%A7%A3.png
	int findUnsortedSubarray_ziji(vector<int>& nums) {
		if(is_sorted(nums.begin(), nums.end())) return 0;

		int size = nums.size();
		int i = 0, j = size - 1;
		while (i < j && nums[i] <= nums[i + 1]) i++;
		while (i < j && nums[j] >= nums[j - 1]) j--;
		int left = i, right = j;

		int minNum = INT_MAX, maxNum = INT_MIN;
		for(int index = left; index <= right; index++) {
			minNum = min(minNum, nums[index]);
			maxNum = max(maxNum, nums[index]);
		}

		for(int leftIndex = 0; leftIndex < left; leftIndex++) {
			if(minNum < nums[leftIndex]) {
				left = leftIndex;
				break;
			}
		}

		for(int rightIndex = size - 1; rightIndex > right; rightIndex--) {
			if(maxNum > nums[rightIndex]) {
				right = rightIndex;
				break;
			};
		}

		return right - left + 1;
	}


	// 找中段的左右边界，我们分别定义为begin 和 end;
	// 分两头开始遍历:
	// 从左到右维护一个最大值max,在进入右段之前，那么遍历到的nums[i]都是小于max的，我们要求的end就是遍历中最后一个小于max元素的位置；
	// 同理，从右到左维护一个最小值min，在进入左段之前，那么遍历到的nums[i]也都是大于min的，要求的begin也就是最后一个大于min元素的位置。

	int findUnsortedSubarray_zuiyou(vector<int>& nums) {
		// maxNum 设成最小的int值，minNum 设成最大的int值(这个初始化很重要），left、right 设置成-1便于区分nums本来就是有序的情况
		int maxNum = INT_MIN, minNum = INT_MAX, size = nums.size();
		int left = -1, right = -1;
		for (int i = 0; i < size; i++) {
			if(nums[i] < maxNum) { // 找最后一个小于 maxNum 的元素下标 right
				right = i;
			} else {
				maxNum = nums[i];
			}

			if (nums[size - i - 1] > minNum) { // 找最后一个大于 minNum 的元素下标 left
				left = size - i - 1;
			} else {
				minNum = nums[size - i - 1];
			}
		}
		return right == -1 ? 0 : right - left + 1;
	}

	// 我们创建数组 nums 的拷贝，记作数组 numsSorted，并对该数组进行排序，然后我们从左向右找到第一个两数组不同的位置，即为 numsB的左边界。同理也可以找到 numsB右边界。最后我们输出numsB的长度即可。
	// 特别地，当原数组有序时，numsB长度为 0，我们可以直接返回结果。

public:
	int findUnsortedSubarray_0(vector<int>& nums) {
		if (is_sorted(nums.begin(), nums.end())) {
			return 0;
		}
		vector<int> numsSorted(nums);
		sort(numsSorted.begin(), numsSorted.end());

		// 寻找左右边界
		int left = 0;
		while (nums[left] == numsSorted[left]) {
			left++;
		}

		int right = nums.size() - 1;
		while (nums[right] == numsSorted[right]) {
			right--;
		}

		return right - left + 1;
	}

	int MIN = -100005, MAX = 100005;
	int findUnsortedSubarray_2(vector<int>& nums) {
		int size = nums.size();
		int i = 0, j = size - 1;
		while (i < j && nums[i] <= nums[i + 1]) i++;
		while (i < j && nums[j] >= nums[j - 1]) j--;
		int left = i, right = j;

		int min = nums[i], max = nums[j];
		for (int midIndex = left; midIndex <= right; midIndex++) {
			if (nums[midIndex] < min) {
				while (i >= 0 && nums[i] > nums[midIndex]) i--;
				min = i >= 0 ? nums[i] : MIN;
			}
			if (nums[midIndex] > max) {
				while (j < size && nums[j] < nums[midIndex]) j++;
				max = j < size ? nums[j] : MAX;
			}
		}
		return j == i ? 0 : (j - 1) - (i + 1) + 1;
	}

};
