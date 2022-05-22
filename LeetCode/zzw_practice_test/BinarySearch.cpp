#include "../../include.h"

class BinarySearch{
public:
	/**
	 * 循环条件： left <= right
		中间位置计算： mid = left + ((right -left) >> 1)
		左边界更新：left = mid + 1
		右边界更新： right = mid - 1
		返回值： mid / -1
		这里有几点需要注意：

		我们的循环条件中包含了 left == right的情况，则我们必须在每次循环中改变 left 和 right的指向，以防止进入死循环
		循环终止的条件包括：

		找到了目标值
		left > right （这种情况发生于当left, mid, right指向同一个数时，这个数还不是目标值，则整个查找结束。）
		left + ((right -left) >> 1) 其实和 (left + right) / 2是等价的，这样写的目的一个是为了防止 (left + right)出现溢出，一个是用右移操作替代除法提升性能。
		left + ((right -left) >> 1) 对于目标区域长度为奇数而言，是处于正中间的，对于长度为偶数而言，是中间偏左的。因此左右边界相遇时，只会是以下两种情况：

		left/mid , right (left, mid 指向同一个数，right指向它的下一个数)
		left/mid/right （left, mid, right 指向同一个数）
		即因为mid对于长度为偶数的区间总是偏左的，所以当区间长度小于等于2时，mid 总是和 left在同一侧
	 * @param nums
	 * @param target
	 * @return
	 */
	// 最基础的二分查找
	int search_704(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}

			if(nums[mid] < target) { // 在右边 {mid + 1, right}
				left = mid + 1;
			} else {  // 在左边 {left, mid - 1}
				right = mid - 1;
			}
		}
		return -1;
	}

public:
	int guess(int num);
	int guessNumber_374(int n) {
		int left = 1, right = n;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(guess(mid) == 0) {
				return mid;
			}

			if (guess(mid) == -1) {  // pick < mid {left, mid - 1}
				right = mid - 1;
			} else { // pick > mid {mid + 1, right}
				left = mid + 1;
			}
		}

		return -1;
	}

public:
	int mySqrt_69(int x) {
		if (x <= 1) {
			return x;
		}

		int left = 1, right = x - 1;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == x / mid) {
				return mid;
			}

			if (mid < x / mid) { // target > mid, {mid + 1, right}
				if ((mid + 1) > x / (mid + 1)) {  // 这里需要额外判断一下
					return mid;
				}

				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		return -1;
	}

public:
	/**
	 二分查找左边界
	利用二分法寻找左边界是二分查找的一个变体，应用它的题目常常有以下几种特性之一：

	数组有序，但包含重复元素
	数组部分有序，且不包含重复元素
	数组部分有序，且包含重复元素
	左边界查找类型1
	类型1包括了上面说的第一种，第二种情况。

	既然要寻找左边界，搜索范围就需要从右边开始，不断往左边收缩，也就是说即使我们找到了nums[mid] == target, 这个mid的位置也不一定就是最左侧的那个边界，我们还是要向左侧查找，所以我们在nums[mid]偏大或者nums[mid]就等于目标值的时候，继续收缩右边界，算法模板如下：

	 循环条件： left < right
	中间位置计算： mid = left + ((right -left) >> 1)
	左边界更新：left = mid + 1
	右边界更新： right = mid
	返回值： nums[left] == target ? left : -1

	 与标准的二分查找不同：
首先，这里的右边界的更新是right = mid，因为我们需要在找到目标值后，继续向左寻找左边界。
其次，这里的循环条件是left < right。
因为在最后left与right相邻的时候，mid和left处于相同的位置(前面说过，mid偏左)，则下一步，无论怎样，left, mid, right都将指向同一个位置，如果此时循环的条件是left <= right，则我们需要再进入一遍循环，此时，如果nums[mid] < target还好说，循环正常终止；否则，我们会令right = mid，这样并没有改变left,mid,right的位置，将进入死循环。

	 事实上，我们只需要遍历到left和right相邻的情况就行了，因为这一轮循环后，无论怎样，left,mid,right都会指向同一个位置，而如果这个位置的值等于目标值，则它就一定是最左侧的目标值；如果不等于目标值，则说明没有找到目标值，这也就是为什么返回值是nums[left] == target ? left : -1。
	 */
	int search_left_bound(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) { // {mid + 1, right}
				left = mid + 1;
			} else {
				right = mid;
			}
		}

		return nums[left] == target ? left : - 1;
	}

	/**
	 左边界查找类型2
	 左边界查找的第二种类型用于数组部分有序且包含重复元素的情况，这种条件下在我们向左收缩的时候，不能简单的令 right = mid，因为有重复元素的存在，这会导致我们有可能遗漏掉一部分区域，此时向左收缩只能采用比较保守的方式，代码模板如下：
	 */
public:
	int search_left_bound_2(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) { // {mid + 1, right}
				left = mid + 1;
			} else if(nums[mid] > target) { // {left, mid - 1}
				right = mid;
			} else {
				right--;
			}
		}

		return nums[left];
	}

public:
	int findMin_153(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] < nums[right]) { // {left, mid}
				right = mid;
			} else { // {mid + 1, right}
				left = mid + 1;
			}
		}

		return nums[left];
	}

public:
	/**
	 * 这道题目和上面的实战2类似，只是多了一个条件——数组中可能包含重复元素，这就是我们之前说的二分查找左边界的第二种类型，在这种情况下，我们只能采用保守收缩的方式，以规避重复元素带来的对于单调性的破坏
	 */
	int findMin_154(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] < nums[right]) {  // {left, mid}   mid 位于旋转点左侧
				right = mid;
			} else if (nums[mid] > nums[right]) { // {mid + 1, right} // mid 位于旋转点右侧
				left = mid + 1;
			} else { // nums[mid] == nums[right]
				right--;  // 注意相等的时候的特殊处理，因为要向左查找左边界，所以直接收缩右边界
			}
		}

		return nums[left];
	}
};

class Solution_BuleRed {
public:
	int search_leetcode704(vector<int>& nums, int target) {
		int n = nums.size();
		int left = -1, right = n;

		while(left +1 != right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] == target) {
				return mid;
			}

			if (target < nums[mid]) {
				left = mid;
			} else {
				right = mid;
			}
		}
		return -1;
	}

	int guess(int num);
	int guessNumber_leetcode374(int n) {
		long long left = 0, right = (long long) n + 1;
		while(left + 1 != right) {
			int mid = left + (right - left) / 2;

			if (guess(mid) == 0) {
				return mid;
			}

			if(guess(mid) > 0) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return -1;
	}

	int searchInsert_leetcode31(vector<int>& nums, int target) {
		int size = nums.size();
		int left = -1, right = size;
		while(left + 1 != right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return right;
	}

	int peakIndexInMountainArray_852(vector<int>& arr) {

		return 0;
	}

	int mySqrt_leetcode69(int x) {
		long long left = -1, right = (long long) x + 1;
		while(left + 1 != right) {
			long long mid = left + (right - left) / 2;
			if (mid * mid <= x) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return left;
	}

	char nextGreatestLetter_leetcode744(vector<char>& letters, char target) {
		// 先处理掉 结果是数组的第一个字符的情况
		if (target >= letters.back()) {
			return letters[0];
		}

		int size = letters.size();
		int left = -1, right = size;

		while(left + 1 != right) {
			int mid = left + (right - left) / 2;
			if (letters[mid] <= target) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return letters[right];
	}

	bool isBadVersion(int num);
	int firstBadVersion_leetcode278(int n) {
        long long left = -1;
        long long right = (long long)n + 1;

        while(left + 1 != right) {
        	long long mid = left + (right - left) / 2;

        	if (isBadVersion(mid) == false) {
				left = mid;
        	} else {
        		right = mid;
        	}
        }

        return right;
	}

	////////////////////////////////////////////////
	int binarySearchLeft(vector<int>& nums, int target) {
		int left = -1, right = nums.size();
		while(left + 1 != right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] < target) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return right;
	}

	int binarySearchRight(vector<int>& nums, int target) {
		int left = -1, right = nums.size();
		while(left + 1 != right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] <= target) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return left;
	}

	vector<int> searchRange_leetcode34(vector<int>& nums, int target) {
		if(nums.empty() || nums.back() < target || nums[0] > target) {
			return {-1, -1};
		}

		int leftIndex = binarySearchLeft(nums, target);
		int rightIndex = binarySearchRight(nums, target);

		if (leftIndex <= rightIndex && rightIndex < nums.size() && leftIndex >= 0) {
			return {leftIndex, rightIndex};
		}

		return {-1, -1};
	}


	int arrangeCoins_leetcode441(int n) {
		long long left = 0, right = (long long) n + 1;

		while(left + 1 != right) {
			long long mid = left + (right - left) / 2;
			if(mid * (mid + 1) <= (long long) n * 2) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return left;
	}

	int findMin_leetcode153(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] < nums[right] ) { // [left, mid]
				right = mid;
			} else {
				left = mid + 1;
			}
		}

		return nums[left];
	}

};

int main_lmki98() {
	Solution_BuleRed bs;
	vector<int> nums = {3,4,5,1,2};
	int inputN = 5;

	//cout << "findMin_153: " << bs.firstBadVersion_leetcode278(nums) << endl;

	return 0;
}