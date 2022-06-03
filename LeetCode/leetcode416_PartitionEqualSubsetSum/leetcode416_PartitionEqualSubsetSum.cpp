// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
 https://leetcode.cn/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/

 作为「0-1 背包问题」，它的特点是：「每个数只能用一次」。解决的基本思路是：物品一个一个选，容量也一点一点增加去考虑，这一点是「动态规划」的思想，特别重要。
在实际生活中，我们也是这样做的，一个一个地尝试把候选物品放入「背包」，通过比较得出一个物品要不要拿走。

具体做法是：画一个 len 行，target + 1 列的表格。这里 len 是物品的个数，target 是背包的容量。len 行表示一个一个物品考虑，target + 1多出来的那 1 列，表示背包容量从 0 开始考虑。很多时候，我们需要考虑这个容量为 0 的数值。

状态与状态转移方程
状态定义：dp[i][j]表示从数组的 [0, i] 这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。
状态转移方程：很多时候，状态转移方程思考的角度是「分类讨论」，对于「0-1 背包问题」而言就是「当前考虑到的数字选与不选」。
（1）不选择 nums[i]，如果在 [0, i - 1] 这个子区间内已经有一部分元素，使得它们的和为 j ，那么 dp[i][j] = true；
（2）选择 nums[i]，如果在 [0, i - 1] 这个子区间内就得找到一部分元素，使得它们的和为 j - nums[i]。
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// dp(压缩空间)
	// 每次迭代只与上一行有关，因此可以压缩成一行 "当做上一行"，但是由于当前行在一行上更新，并且当前行的数据 需要根据上一行前面的数据得出
	// 因此为了避免更新时覆盖，所以"从后往前更新"
	bool canPartition(vector<int> &nums) {
		int size = nums.size();

		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0) {   // 和为奇数直接返回false
			return false;
		}

		int target = sum / 2;
		vector<bool> dp(target + 1, false);
		dp[0] = true;

		for (int i = 1; i <= size; ++i) {
			int num = nums[i - 1];
			for (int j = target; j >= 0; --j) {  // 从后往前更新
				if (j >= nums[i - 1]) {
					dp[j] = dp[j] || dp[j - num];
				}
			}
		}

		return dp[target];
	}

	// dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j
	bool canPartition_ver0(vector<int> &nums) {
		int size = nums.size();

		int total = 0, maxNum = INT_MIN;
		for (int e : nums) {
			total += e;
			maxNum = max(maxNum, e);
		}

		if (total % 2 != 0 || maxNum > total / 2) return false;
		int target = total / 2;

		vector<vector<bool>> dp(size, vector<bool>(target + 1, false)); // dp[i][j] 在[0,i]中选择，是否能达成和为j
		for (int i = 0; i < size; i++) { // 初始化第一列
			dp[i][0] = true;
		}

		// 初始化第一行
		dp[0][nums[0]] = true;
		for (int i = 1; i < size; i++) {
			int num = nums[i];
			for (int j = 1; j <= target; j++) {
				int index = j - num;
				if (index >= 0) {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][index];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		return dp[size - 1][target];
	}




	bool canPartition_print(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) {
			return false;
		}
		int sum = 0, maxNum = 0;
		for(auto element : nums) {
			maxNum = max(maxNum, element);
			sum += element;
		}

		if (sum & 1)  return false;
		int target = sum / 2;
		if (maxNum > target)  return false;

		vector<vector<bool>> dp(size, vector<bool>(target + 1, false));
		//print_vector_vector(dp);
		// 初始化，当 j和为0，都是为true，因为可以都不取
		for (int i = 0; i < size; i++) {
			dp[i][0] = true;
		}
		//print_vector_vector(dp);

		dp[0][nums[0]] = true;
		//print_vector_vector(dp);
		for (int i = 1; i < size; i++) {
			int curIndex = nums[i];
			for (int j = 1; j <= target; j++) {
				if (j >= curIndex) {
					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - curIndex];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
				//print_vector_vector(dp);
			}
		}

		return dp[size - 1][target];
	}
};

/**
// 0-1背包问题母代码(二维)
int bags()
{
    vector<int> weight = {1, 3, 4};   //各个物品的重量
    vector<int> value = {15, 20, 30}; //对应的价值
    int bagWeight = 4;                //背包最大能放下多少重的物品

    // 二维数组：状态定义:dp[i][j]表示从0-i个物品中选择不超过j重量的物品的最大价值
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));

    // 初始化:第一列都是0，第一行表示只选取0号物品最大价值
    for (int j = bagWeight; j >= weight[0]; j--)
        dp[0][j] = dp[0][j - weight[0]] + value[0];

    // weight数组的大小 就是物品个数
    for (int i = 1; i < weight.size(); i++) // 遍历物品(第0个物品已经初始化)
    {
        for (int j = 0; j <= bagWeight; j++) // 遍历背包容量
        {
            if (j < weight[i])           //背包容量已经不足以拿第i个物品了
                dp[i][j] = dp[i - 1][j]; //最大价值就是拿第i-1个物品的最大价值
            //背包容量足够拿第i个物品,可拿可不拿：拿了最大价值是前i-1个物品扣除第i个物品的 重量的最大价值加上i个物品的价值
            //不拿就是前i-1个物品的最大价值,两者进行比较取较大的
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    return dp[weight.size() - 1][bagWeight];
}

int test_1_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++)
    { // 遍历物品
        for (int j = bagWeight; j >= weight[i]; j--)
        {                                                     // 遍历背包容量(一定要逆序)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); //不取或者取第i个
        }
    }

    return dp[bagWeight];
}


**/