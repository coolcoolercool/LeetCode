#include "../../include.h"

/*
 最长递增子序列的长度
 */

class SolutionMethod {
public:
	/*
	方法一：动态规划
	https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
	定义 dp[i] 为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度，注意 nums[i] 必须被选取
    */
	int lengthOfLIS_1(vector<int>& nums) {
		if (nums.empty()) return 0;

		int size = nums.size();
		vector<int> dp(size, 0);
		int res = 0;
		for (int index = 0; index < size; index++) {
			dp[index] = 1;
			for (int j = 0; j < index; j++) { // j in [0, mp)
				if (nums[j] < nums[index]) {
					dp[index] = max(dp[index], dp[j] + 1); // 计算以 mp 索引结尾，在0 ~ mp - 1，最大连续递增子序列的长度
				}
			}
			res = max(res, dp[index]);
		}
		return res;
	}

	/*
		// dp(贪心) + 二分查找 (时: N*logN)
		// dp[i]表示存储长度为 i+1 的最长递增子序列的 最后一个数字
		// 遍历每一个位置 i，如果其对应的数字大于 dp 数组中所有数字的值，那么把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
		// 如果发现这个数字在 dp 数组中比数字 a 大、比数字 b 小，则将 b 更新为此数字，使得之后构成递增序列的可能性增大(贪心)。
		// 以这种方式维护的 dp 数组永远是递增的，因此可以用二分查找加速搜索。

		很具小巧思。新建数组 cell，用于保存最长上升子序列。
		对原序列进行遍历，将每位元素二分插入 cell 中。
		如果 cell 中元素都比它小，将它插到最后
		否则，用它覆盖掉比它大的元素中最小的那个。(第一个比他大的数字)
		总之，思想就是让 cell 中存储比较小的元素。这样，cell 未必是真实的最长上升子序列，但长度是对
    */
	int lengthOfLIS_2(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++) {
			// 如果nums[i]大于 dp 数组中所有数字的值，那么把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
			if (res.back() < nums[i]) {
				res.push_back(nums[i]);
			} else {
				// 如果发现这个数字在 dp 数组中比数字 a 大、比数字 b 小，则将 b 更新为此数字，使得之后构成递增序列的可能性增大
				// lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素
				auto iter = std::lower_bound(res.begin(), res.end(), nums[i]); // 注意这里是在res里面搜索
				*iter = nums[i];
			}
		}

		return res.size();
	};

};

/*
C++ lower_bound()函数
lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。也就是说，使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素。
此外，该函数还会返回一个正向迭代器，当查找成功时，迭代器指向找到的元素；反之，如果查找失败，迭代器的指向和 last 迭代器相同。
再次强调，该函数仅适用于已排好序的序列。所谓“已排好序”，指的是 [first, last) 区域内所有令 element<val（或者 comp(element,val)，其中 element 为指定范围内的元素）成立的元素都位于不成立元素的前面。
 */

int main_ok097() {
	SolutionMethod sol;
	vector<int> nums = {0,1,0,3,2,3};
	int res = sol.lengthOfLIS_2(nums);

	cout << res << endl;

	return 0;
}
