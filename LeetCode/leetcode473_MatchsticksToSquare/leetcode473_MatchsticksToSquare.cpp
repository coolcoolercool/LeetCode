// Created by rainyzwzhou on 2022/6/1.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/matchsticks-to-square/solution/hui-su-suan-fa-jie-jue-ji-you-hua-chao-g-9iyl/
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool res = false;

	// index表示访问到当前火柴的位置，target表示正方形的边长，size是长度为4的数组，
	// 分别保存正方形4个边的长度
	void help(vector<int> &nums, int index, int target, vector<int> &oneRes) {
		if (index == nums.size()) { // 如果火柴都访问完了，并且size的4个边的长度都相等，说明是正方形，直接返回true。如果火柴能用完，那么一定是四条边等长，所以这里不再重复判断四条边长是否相等
			res = true;
			return;
		} else {
			for (int i = 0; i < oneRes.size() && res == false; i++) {  // 到这一步说明火柴还没访问完
				if (oneRes[i] + nums[index] > target) continue;   // 如果把当前火柴放到size[i]这个边上，他的长度大于target，我们直接跳过

				oneRes[i] += nums[index];    // 如果当前火柴放到size[i]这个边上，长度不大于target，我们就放上面
				help(nums, index + 1, target, oneRes);   // 然后在放下一个火柴，如果最终能变成正方形，直接返回true
				oneRes[i] -= nums[index];    // 如果当前火柴放到size[i]这个边上，最终不能构成正方形，我们就把他从 size[i]这个边上给移除，然后在试其他的边
			}
		}
	}

	bool makesquare(vector<int> &matchsticks) {
		int size = matchsticks.size();
		int totalLen = 0;
		for (int i = 0; i < size; i++) {  //统计所有火柴的长度，如果所有火柴的长度不是4的倍数，直接返回false，因为肯定不能拼接成等长的4边
			totalLen += matchsticks[i];
		}
		if (totalLen % 4 != 0) return false;

		sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 这里排序，使得顺序从大到小，加快遍历结果的速度，否则会超时
		int len = totalLen / 4;
		vector<int> oneRes(4);

		help(matchsticks, 0, len, oneRes);

		return res;
	}
};

/**
// 回溯递归调用模板
void backtrack("原始参数") {
    //终止条件(递归必须要有终止条件)
    if ("终止条件") {
        //一些逻辑操作（可有可无，视情况而定）
        return;
    }

    for (int i = "for循环开始的参数"; i < "for循环结束的参数"; i++) {
        //一些逻辑操作（可有可无，视情况而定）

        //做出选择

        //递归
        backtrack("新的参数");
        //一些逻辑操作（可有可无，视情况而定）

        //撤销选择
    }
}
**/