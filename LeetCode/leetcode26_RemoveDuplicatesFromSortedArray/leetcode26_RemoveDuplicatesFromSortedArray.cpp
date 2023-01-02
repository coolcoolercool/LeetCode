//
// Created by rainyzwzhou on 2022/5/2.
//

#include "../../include.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) {
			return 0;
		}

		int newSize = 0;
		for(int i = 0; i < size; i++) {
			if(nums[newSize] != nums[i]) {
				newSize++;
				nums[newSize] = nums[i];
			}
		}

		return newSize + 1;
	}
};