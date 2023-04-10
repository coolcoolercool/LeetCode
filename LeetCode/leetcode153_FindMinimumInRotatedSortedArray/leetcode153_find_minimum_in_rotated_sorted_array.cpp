#include "../../include.h"

/**
题目: 循转递增数组，元素互不相同，找最小值

题目解析:
 https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/solutions/126635/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/
 */

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[right]) { // 最小值在左边, left ~ mid
				right = mid;   // 这里 right = mid，是为了避免遗漏 mid 就是最小值的情况
			} else { // 最小值在右边，mid + 1 ～ right (nums[mid] > nums[right])
				left = mid + 1;
			}
		}

		return nums[left];
	}
};

/*
 //           如果中间值小于最大值，则最大值减小
//            疑问：为什么 high = mid;而不是 high = mid-1;
//            解答：{4,5,1,2,3}，如果high=mid-1，则丢失了最小值1


//            如果中间值大于最大值，则最小值变大
//            疑问：为什么 low = mid+1;而不是 low = mid;
//            解答：{4,5,6,1,2,3}，nums[mid]=6，low=mid+1,刚好nums[low]=1
//            继续疑问：上边的解释太牵强了，难道没有可能low=mid+1,正好错过了最小值
//            继续解答：不会错过!!! 如果nums[mid]是最小值的话，则其一定小于nums[high],走if，就不会走else了

//        疑问：为什么while的条件是low<high,而不是low<=high呢
//        解答：low<high，假如最后循环到{*,10,1,*}的这种情况时，nums[low]=10,nums[high]=1,nums[mid]=10,low=mid+1,
//             直接可以跳出循环了,所以low<high,此时low指向的就是最小值的下标;
//             如果low<=high的话，low=high，还会再不必要的循环一次，此时最后一次循环的时候会发生low==high==mid，
//             则nums[mid]==nums[high]，则会走一次else语句，则low=mid+1,此时low指向的是最小值的下一个下标，
//             则需要return[low-1]

 */






