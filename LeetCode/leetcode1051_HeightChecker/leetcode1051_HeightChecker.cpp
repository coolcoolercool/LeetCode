// Created by 周子望 on 2022/6/13.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/height-checker/solution/onjie-fa-yong-shi-yu-nei-cun-ji-bai-100-javayong-h/
利用计数排序或者说桶排序，将元素排列成非递减的顺序，然后与原数组对比

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int size = heights.size();
		vector<int> arr(101); // 因为heights[i]的取值范围是[1,100]
		for(int i : heights) { // 遍历数组heights，计算每个桶中有多少个元素，也就是数组heights中有多少个1，多少个2，。。。，多少个100
			arr[i]++;
		}

		int res = 0;
		for(int i = 1, j = 0; i < arr.size(); i++) { // arr[i]，i就是桶中存放的元素的值，arr[i]是元素的个数
			while(arr[i] > 0) {
				if(heights[j] != i) { // 从桶中取出元素时，元素的排列顺序就是非递减的，然后与heights中的元素比较，如果不同，计算器就加1
					res++;
				}
				j++;
				arr[i]--;
			}
		}

		return res;
	}
};


// 直接复制一份数组排序，然后跟原数组对比，计算不符合预期的数量
class Solution_ver0 {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> sortHeights = heights;
		sort(sortHeights.begin(), sortHeights.end());

		int size = heights.size(), res = 0;
		for(int i = 0; i < size; i++) {
			if(heights[i] != sortHeights[i]) res++;
		}

		return res;
	}
};