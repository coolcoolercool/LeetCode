// Created by 周子望 on 2022/10/16.
#include "../../include.h"

/**
题目描述:

核心思想:
如果后一个时间点在前一个时间点的持续时间之外 则总时间直接加一个duration 否则 总时间只加上前后时间点的时间差。 循环结束后 最后一个时间点还没算 但后面已经没有时间点了故需要直接加一个duration。
**/

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int result = 0, end = 0;
		for(int i = 0; i < timeSeries.size(); i++) {
			if (timeSeries[i] >= end) {
				result += duration;
			} else {
				result += timeSeries[i] + duration - end;
			}
			end = timeSeries[i] + duration;
		}
		return result;
	}

	int findPoisonedDuration_ziji(vector<int>& timeSeries, int duration) {
		int result = 0, start = -1, end = -1;
		for(int i = 0; i < timeSeries.size(); i++) {
			if (start == -1) {
				start = timeSeries[i];
				end = timeSeries[i] + duration;
			}
			if (end >= timeSeries[i]) {
				end = timeSeries[i] + duration;
			} else {
				result += end - start;

				start = timeSeries[i];
				end = timeSeries[i] + duration;
			}
			if (i == timeSeries.size() - 1) {
				result += end - start;
			}
		}

		return result;
	}
};

