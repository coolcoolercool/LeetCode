// Created by rainyzwzhou on 2022/6/3.

/**
题目描述:

核心思想:
**/
#include "../../include.h"
#include <bits/stdc++.h>

using namespace std;

int cntcount = 0;
vector<string> ans;

void dfs(int n, int cur, string s) {
	if (cur == n) {
		cntcount++;
		ans.push_back(s);
		return;
	}
	if (cur > n) return;
	dfs(n, cur + 1, s + to_string(cur + 1));
	dfs(n, cur + 2, s + to_string(cur + 2));
}

int main_0ok1km() {
	int n;
	cin >> n;
	dfs(n, 0, "0");
	cout << cntcount << endl;
	for (auto &s : ans) {
		cout << s << endl;
	}
}


/* 快排 */
class QuickSort {
public:
	int partition(vector<int>& arr, int left, int right) {
		int temp = rand() % (right - left + 1) + left;
		swap(arr[temp], arr[left]);

		int pivot = left;
		int index = left + 1;
		for(int i = index; i <= right; i++) {
			if(arr[i] < arr[pivot]) {
				swap(arr[i], arr[index]);
				index++;
			}
		}
		swap(arr[index - 1], arr[pivot]);
		return index - 1;
	}

	void quickSort(vector<int>& arr, int left, int right) {
		if(left < right) {
			int partitionIndex = partition(arr, left, right);
			quickSort(arr, left, partitionIndex - 1);
			quickSort(arr, partitionIndex + 1, right);
		}
	}

	void quickSort(vector<int>& arr) {
		quickSort(arr, 0, arr.size() - 1);
	}
};

class MergeSort {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
		vector<int> tempArr(right - left + 1);
		int curLeft = left;
		int curRight = mid + 1;
		int curIndex = 0;

		while(curLeft <= mid && curRight <= right) {
			if(arr[curLeft] < arr[curRight]) {
				tempArr[curIndex] = arr[curLeft];
				curIndex++, curLeft++;
			} else {
				tempArr[curIndex] = arr[curRight];
				curIndex++, curRight++;
			}
		}

		while(curLeft <= mid) {
			tempArr[curIndex++] = arr[curLeft++];
		}
		while(curRight <= right) {
			tempArr[curIndex++] = arr[curRight++];
		}
		for(int i = 0; i < right - left + 1; i++) {
			arr[i + left] = tempArr[i];
		}

	}

	void mergeSort(vector<int>& arr, int left, int right) {
		int mid = left + (right - left) / 2;
		if(left < right) {
			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}

	void mergeSort(vector<int>& arr) {
		mergeSort(arr, 0, arr.size() - 1);
	}
};


class BinarySearch{
public:
	vector<int> preorder(TreeNode* root) {
		vector<int> res;
		if(root == nullptr) return res;
		stack<TreeNode*> st;
		while(root != nullptr || !st.empty()) {
			while(root != nullptr) {
				st.push(root);
				res.push_back(root->val);
				root = root->left;
			}
			root = st.top();
			st.pop();
			root = root->right;
		}
	}

	vector<int> inorder(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		while(root != nullptr || !st.empty()) {
			while(root != nullptr) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}
};