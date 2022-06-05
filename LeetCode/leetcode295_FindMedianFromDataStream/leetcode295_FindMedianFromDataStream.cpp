// Created by rainyzwzhou on 2022/5/21

/**
题目描述:

核心思想:
https://leetcode.cn/problems/find-median-from-data-stream/solution/gong-shui-san-xie-jing-dian-shu-ju-jie-g-pqy8/

这是一道经典的数据结构运用题。
具体的，我们可以使用两个优先队列（堆）来维护整个数据流数据，令维护数据流左半边数据的优先队列（堆）为 l，维护数据流右半边数据的优先队列（堆）为 rLen。
显然，为了可以在 O(1)O(1) 的复杂度内取得当前中位数，我们应当令 l 为大根堆，rLen 为小根堆，并人为固定 l 和 rLen 之前存在如下的大小关系：
(1)当数据流元素数量为偶数：l 和 rLen 大小相同，此时动态中位数为两者堆顶元素的平均值；
(2)当数据流元素数量为奇数：l 比 rLen 多一，此时动态中位数为 l 的堆顶原数。

为了满足上述说的奇偶性堆大小关系，在进行 addNum 时，我们应当分情况处理：
插入前两者大小相同，说明插入前数据流元素个数为偶数，插入后变为奇数。我们期望操作完达到「l 的数量为 rLen 多一，同时双堆维持有序」，进一步分情况讨论：
(1)如果 rLen 为空，说明当前插入的是首个元素，直接添加到 l 即可；
(2)如果 rLen 不为空，且 num <= rLen.peek()，说明 num 的插入位置不会在后半部分（不会在 rLen 中），直接加到 l 即可；
(3)如果 rLen 不为空，且 num > rLen.peek()，说明 num 的插入位置在后半部分，此时将 rLen 的堆顶元素放到 l 中，再把 num 放到 rLen（相当于从 rLen 中置换一位出来放到 l 中）。

 插入前两者大小不同，说明前数据流元素个数为奇数，插入后变为偶数。我们期望操作完达到「l 和 rLen 数量相等，同时双堆维持有序」，进一步分情况讨论（此时 l 必然比 rLen 元素多一）：
(1)如果 num >= l.peek()，说明 num 的插入位置不会在前半部分（不会在 l 中），直接添加到 rLen 即可。
(2)如果 num < l.peek()，说明 num 的插入位置在前半部分，此时将 l 的堆顶元素放到 rLen 中，再把 num 放入 l 中（相等于从 l 中替换一位出来当到 rLen 中）。

**/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
	priority_queue<int, vector<int>, less<int>> leftQueue; // 保存小于等于中位数的数
	priority_queue<int, vector<int>, greater<int>> rightQueue; // 保存大于等于中位数的数
	int leftSize = 0, rightSize = 0; // leftSize >= rightSize

	MedianFinder() {}

	void addNum(int num) {
		leftSize = leftQueue.size(), rightSize = rightQueue.size();
		if(leftSize == rightSize) { //  插入前两者大小相同，说明插入前数据流元素个数为偶数，插入后变为奇数
			if(rightQueue.empty() || num <= rightQueue.top()) { // 这里使用left还是right，主要是后面要求right非空
				leftQueue.push(num);
			} else { // rightQueue.top() < num，num应该去right
				leftQueue.push(rightQueue.top());
				rightQueue.pop();
				rightQueue.push(num);
			}
		} else { // leftSize > rightSize, 需要往right中新增一个元素
			if(leftQueue.top() <= num) {
				rightQueue.push(num);
			} else { // leftQueue.top() > num，num应该去left
				rightQueue.push(leftQueue.top());
				leftQueue.pop();
				leftQueue.push(num);
			}
		}
	}

	double findMedian() {
		leftSize = leftQueue.size(), rightSize = rightQueue.size();
		if (leftSize > rightSize) {
			return leftQueue.top();
		} else {
			return (leftQueue.top() + rightQueue.top()) / 2.0;
		}
	}
};