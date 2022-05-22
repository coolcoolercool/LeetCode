// Created by rainyzwzhou on 2022/5/21.

/**
题目描述:
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释:
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

核心思想:

f（i，j）：= 将word1的前i个字符转换为word2的前j个字符所需的最低成本（或步长）

情况1：word1 [i] == word2 [j]，即第j个字符匹配的第i个。 不需要调整
f（i，j）= f（i - 1，j - 1）

案例2：word1 [i] != word2 [j]，那么我们必须插入，删除或替换，以较低成本的为准
f（i，j）= 1 + min {f（i，j - 1），f（i - 1，j），f（i - 1，j - 1）}
1.f（i，j-1）表示插入操作
2.f（i-1，j）表示删除操作
3.f（i-1，j-1）表示替换操作

在这里，我们考虑从word1到word2的任何操作。这意味着，当我们说插入操作时，我们在word1之后插入一个与word2的第j个字符匹配的新字符。
所以，现在必须匹配word1的i个字符到word2的j - 1个字符。其他2个操作也是如此。

请注意，问题是对称的。在一个方向上（即从word1到word2）的插入操作与在其他方向上的删除操作相同。所以，我们可以选择任何方向。
上面的等式成为DP的递归定义。

基本情况：
f（0，k）= f（k，0）= k
时间复杂度：如果n是word1的长度，则是word2的m，由于两个缩进的循环，它是O（nm）
**/
#include <bits/stdc++.h>
using namespace std;

class Solution {
	// f（i，j）：= 将word1的前i个字符(str(0, i-1))转换为word2的前j个字符(str(0, j - 1))所需的最低成本（或步长）
	// cost[i][j];    之前所有字段匹配的代价总和
	// cost[i][j+1];  删除操作的代价
	// cost[i+1][j];  插入操作的代价
public:
	int minDistance(string word1, string word2) {  // word1 -> word2
		int len1 = word1.size();
		int len2 = word2.size();

		vector<vector<int>> cost(len1 + 1, vector<int>(len2 + 1));
		for (int i = 0; i <= len1; i++) cost[i][0] = i;
		for (int j = 1; j <= len2; j++) cost[0][j] = j;

		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (word1[i] == word2[j]) {  // 字符匹配的情况，不需要增加任何代价
					cost[i + 1][j + 1] = cost[i][j];
				} else {       // 字符不匹配的情况

					cost[i + 1][j + 1] = min(cost[i][j], min(cost[i][j + 1], cost[i + 1][j])) + 1;
				}
			}
		}
		return cost[len1][len2];
	}

};