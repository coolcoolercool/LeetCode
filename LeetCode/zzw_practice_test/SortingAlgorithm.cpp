#include "../../include.h"

/**
题目描述:

核心思想:

https://leetcode.cn/problems/sort-an-array/solution/shi-da-pai-xu-suan-fa-c-by-devinli-gizk/

 */


using namespace std;

class SortingAlgorithm{
public:
	// 归并排序
	/**
	 * 核心思想:
	 * 1、申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
	 * 2、设定两个指针，最初位置分别为两个已经排序序列的起始位置；
	 * 3、比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
	 * 4、重复步骤 3 直到某一指针达到序列尾；
	 * 5、将另一序列剩下的所有元素直接复制到合并序列尾。
	 */

	/**
	 * 对于两个有序的子数组进行合并
	 * left~mid是左子数组，mid+1~right是右子数组
	 * @param arr
	 * @param left
	 * @param mid
	 * @param right
	 */
	void merge(int arr[], int left, int mid, int right) {
		int* tempArr = new int[right - left + 1];
		int curLeft = left;  //左子数组的当前索引，从left开始， left ～ mid
		int curRight = mid + 1;  //右子数组的当前索引，从mid+1开始，mid + 1 ～ right
		int curIndex = 0; // 当前tempArr数组的当前索引

		// 将两个子数组中较小的数先放到辅助数组中
		while (curLeft <= mid && curRight <= right) {
			if (arr[curLeft] < arr[curRight]) {
				tempArr[curIndex] = arr[curLeft];
				curIndex++; curLeft++;
			} else {
				tempArr[curIndex] = arr[curRight];
				curIndex++; curRight++;
			}
		}

		while(curLeft <= mid) {
			tempArr[curIndex++] = arr[curLeft++];  //将左子数组的剩余数依次放到辅助数组中
		}

		while(curRight <= right) {
			tempArr[curIndex++] = arr[curRight++];  //将右子数组的剩余数依次放到辅助数组中
		}

		// 将合并后的辅助数组的元素，覆盖原数组中, 注意这里是 i+left
		for(int i = 0; i < right - left + 1; i++) {
			arr[i + left] = tempArr[i];
		}
	}

	/**
	 * 递归调用
	 * @param arr
	 * @param left
	 * @param right
	 */
	void mergeSort(int arr[], int left, int right) {
		int mid = left + (right - left) / 2;
		if (left < right) {
			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}

	void mergeSort(int arr[], int length) {
		if (arr == nullptr || length < 2) {
			return;
		}
		mergeSort(arr, 0, length - 1);
	}


	// 快速排序
	/**
	 * 核心思想:
	 * 1、从数列中挑出一个元素，称为 “基准”（pivot）;
	 * 2、重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
	 * 在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
	 * 3、递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
	 * 每次的迭代（iteration）中，它至少会把一个元素摆到它最后的位置去。
	 */

	/**
	 * 交换数组两个数
	 * @param arr
	 * @param i
	 * @param j
	 */
	 void swap(int arr[], int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	 }

	 /**
	  * 将枢纽值 pivot 放到数组合适的位置。具体说，就是数组中，枢纽值大于在它左边的元素值，小于等于在它右边元素的值.
	  * 这里index，可以看成冒泡，找到当前自己有序应该在位置，因为index++多加了一次，所以最后 swap 的时候 mp - 1
	  * @param arr
	  * @param left
	  * @param right
	  * @return
	  */
	 int partition(int arr[], int left, int right) {
	 	int pivot = left;
	 	int index = pivot + 1;

	 	for (int i = index; i <= right; i++) {
	 		if (arr[i] < arr[pivot]) {  // 将小于pivot的索引的值，放在index的左边，最后将index - 1和pivot交换，则pivot左边都是小于pivot的值
	 			swap(arr, i, index);
	 			index++;
	 		}
	 	}
	 	swap(arr, pivot, index - 1);
	 	return index - 1;
	 }

	 int partition_1(int arr[], int left, int right) {
	 	int pivot = left;
	 	while(left < right) {
	 		while(left < right && arr[right] >= arr[pivot]) {
	 			right--;
	 		}

	 		arr[left] = arr[right];
	 		while(left < right && arr[left] <= arr[pivot]) {
	 			left++;
	 		}

	 		arr[left] = arr[right];
	 	}

	 	arr[left] = arr[pivot];
	 	return left;
	 }

	 int randomized_partition(vector<int>& nums, int l, int r) {
		 int i = rand() % (r - l) + l; // 随机选一个作为我们的主元
		 std::swap(nums[l], nums[i]);
	 }


	 void quickSort(int arr[], int left, int right) {
	 	if (left < right) {
	 		int partitionIndex = partition(arr, left, right);
	 		quickSort(arr, left, partitionIndex - 1);  //对于枢纽值的左半部分和枢纽值的右半部分，分别递归调用函数进行快排
	 		quickSort(arr, partitionIndex + 1, right);
	 	}
	 }

	 void quickSort(int arr[], int length) {
	 	if (arr == nullptr || length < 2) {
	 		return;
	 	}
	 	quickSort(arr, 0, length - 1);
	 }

	 // 冒泡排序
	 /**
	  * 冒泡排序（Bubble Sort）也是一种简单直观的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
		作为最简单的排序算法之一，冒泡排序给我的感觉就像 Abandon 在单词书里出现的感觉一样，每次都在第一页第一位，所以最熟悉。冒泡排序还有一种优化算法，就是立一个 flag，当在一趟序列遍历中元素没有发生交换，则证明该序列已经有序。但这种改进对于提升性能来说并没有什么太大作用。
	  * @param arr
	  * @param length
	  */
	 void BubbleSort (vector<int>& arr, int length) {
	 	for(int i = 1; i < length; i++) {
	 	    bool flag = true;

	 	    for(int j = 0; j < length - i; j++) { // 需要循环次数
	 	    	if (arr[j] > arr[j + 1]) {
	 	    		std::swap(arr[j], arr[j + 1]);  // 每一次将最大元素，放到数组无序部分的最右边
					flag = false;
	 	    	}
	 	    }

	 	    if (flag) break;
	 	}
	 }

	 // 堆排序
	 void adjustHeap(vector<int> &arr, int curIndex, int len) {
	 	int maxIndex = curIndex;
	 	//如果有左子树，且左子树大于父节点，则将最大指针指向左子树
	 	if (curIndex * 2 + 1 < len && arr[curIndex * 2 + 1] > arr[maxIndex])
	 		maxIndex = curIndex * 2 + 1;
	 	//如果有右子树，且右子树大于父节点和左节点，则将最大指针指向右子树
	 	if (curIndex * 2 + 2 < len && arr[curIndex * 2 + 2] > arr[maxIndex])
	 		maxIndex = curIndex * 2 + 2;
	 	//如果父节点不是最大值，则将父节点与最大值交换，并且递归调整与父节点交换的位置。
	 	if (maxIndex != curIndex) {
	 		std::swap(arr[maxIndex], arr[curIndex]);
	 		adjustHeap(arr, maxIndex, len);
	 	}
	 }

	 void Sort(vector<int> &arr) {
	 	int len = arr.size();
	 	//1.构建一个最大堆
	 	for (int i = len / 2 - 1; i >= 0; i--) {
	 		adjustHeap(arr, i, len); //从最后一个非叶子节点开始
	 	}

	 	//2.循环将堆首位（最大值）与末位交换，然后在重新调整最大堆
	 	for (int i = len - 1; i > 0; i--) {
	 		std::swap(arr[0], arr[i]);
	 		adjustHeap(arr, 0, i);
	 	}
	 }

};

class Solution_HeadSort {
private:
	void head_down(int curIndex, int size, vector<int> &nums) {
		while (curIndex < size) {
			int left = 2 * curIndex + 1, right = 2 * curIndex + 2;
			int max = curIndex;
			if (left < size && nums[left] > nums[max])
				max = left;
			if (right < size && nums[right] > nums[max])
				max = right;
			if (max == curIndex)
				break;
			swap(nums[curIndex], nums[max]);
			curIndex = max;
		}
	}

	void maxHeapity(vector<int> &nums, int size) {
		for (int i = size / 2 - 1; i >= 0; i--)
			head_down(i, size, nums);
	}

public:
	vector<int> sortArray(vector<int> &nums) {
		int n = nums.size();
		maxHeapity(nums, n);
		swap(nums[0], nums[n - 1]);
		for (int i = n - 2; i > 0; i--) {
			n--;
			head_down(0, n, nums);
			swap(nums[0], nums[i]);
		}
		return nums;
	}
};


static void print_arr(int arr[], int length) {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int main_i9mk7() {
	int arr[] = {6,2,3,5,7,4,1,8};
	int length = 8;
	SortingAlgorithm sort;
	sort.quickSort(arr, length);

	print_arr(arr, length);

	return 0;
}