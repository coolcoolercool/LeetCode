// Created by rainyzwzhou on 2022/5/11.

/**
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> dire = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int res = 0;
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int curX, int curY) {
		visited[curX][curY] = true;

		for(int i = 0; i < dire.size(); i++) {
			int newX = curX + dire[i][0], newY = curY + dire[i][1];
			if( newX >= 0 && newX < grid.size() &&
			newY >= 0 && newY < grid[0].size() && visited[newX][newY] == false && grid[newX][newY] == '1') {  // 注意这里先检查边界是否合法，在调用visited和grid，否则会越界
				dfs(grid, visited, newX, newY);
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		if(grid.empty() || grid[0].empty()) {
			return 0;
		}

		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
		for(int i = 0; i < grid.size(); i++) {
			for(int j = 0; j < grid[0].size(); j++) {
				if(visited[i][j] == false && grid[i][j] == '1') {
					res++;
					dfs(grid, visited, i, j);
				}
			}
		}
		return res;
	}
};

