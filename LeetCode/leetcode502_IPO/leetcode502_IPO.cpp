// Created by 周子望 on 2023/1/2.

/**
题目描述:


核心思想:
 贪心 + 优先队列
我们首先思考，如果不限制次数下我们可以获取的最大利润，我们应该如何处理？我们只需将所有的项目按照资本的大小进行排序，依次购入项目 iii，同时手中持有的资本增加 profits[i]\textit{profits}[i]profits[i]，直到手中的持有的资本无法启动当前的项目为止。
(1)如果初始资本 w≥max(capital)，我们直接返回利润中的 k 个最大元素的和即可。
(2)当前的题目中限定了可以选择的次数最多为 k 次，这就意味着我们应该贪心地保证选择每次投资的项目获取的利润最大，这样就能保持选择 kkk 次后获取的利润最大。
(3)我们首先将项目按照所需资本的从小到大进行排序，每次进行选择时，假设当前手中持有的资本为 w，我们应该从所有投入资本小于等于 w 的项目中选择利润最大的项目 j，然后此时我们更新手中持有的资本为 w+profits[j]w，同时再从所有花费资本小于等于 w+profits[j]w 的项目中选择，我们按照上述规则不断选择 k 次即可。
(4)我们利用大根堆的特性，我们将所有能够投资的项目的利润全部压入到堆中，每次从堆中取出最大值，然后更新手中持有的资本，同时将待选的项目利润进入堆，不断重复上述操作。
(5)如果当前的堆为空，则此时我们应当直接返回。
https://leetcode.cn/problems/ipo/solutions/984750/ipo-by-leetcode-solution-89zm/

深交所2022.11.07的招聘笔试中的题目
**/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		int size = profits.size();
		int cur = 0;
		priority_queue<int, vector<int>, less<int>> pq; // 最大堆，大根堆
		vector<pair<int, int>> vec;

		for(int i = 0; i < size; i++) {
			vec.push_back(pair<int, int>{capital[i], profits[i]});
		}
		sort(vec.begin(), vec.end()); // 按照将所需要的资本从小到大排序 capital 升序， 如果capital相等，则按照 profits 从小到大的顺序。即capital相等的时候，profits是按照从小到大的顺序

		// 这里的 vec的索引会被划成k个阶段，每个阶段中会选择当前所需资本的最大利润的项目，然后更新资本，再进入下一个阶段(阶段的索引不会重叠， 所以也不会重复选择同一个项目)，选择利润最大的项目，循环处理
		for(int i = 0; i < k; i++) {
			while(cur < size && vec[cur].first <= w) {
				pq.push(vec[cur].second);
				cur++;
			}
			if (!pq.empty()) {
				w += pq.top();
				pq.pop();
			} else {
				break;
			}
		}
		return w;
	}
};