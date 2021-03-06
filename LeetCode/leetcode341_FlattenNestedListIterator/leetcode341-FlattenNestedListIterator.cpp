//
// Created by rainyzwzhou on 2022/4/27.
//

#include "../../include.h"

class NestedIterator {
private:
	vector<int> vals;
	vector<int>::iterator cur;

	void dfs(const vector<NestedInteger>& nestedList) {
		for(auto &nest : nestedList) {
			if(nest.isInteger()) {
				vals.push_back(nest.getInteger());
			} else {
				dfs(nest.getList());
			}
		}
	}

public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		dfs(nestedList);
		cur = vals.begin();
	}

	int next() {
		return *cur++;
	}

	bool hasNext() {
		return cur != vals.end();
	}
};

