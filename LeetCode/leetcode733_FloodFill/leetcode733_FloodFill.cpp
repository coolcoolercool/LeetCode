#include "../../include.h"

/*
 row 行数  col 列数
 row = vec.size() col = vec[0].size()
 */


class SolutionMethod {
public:
	const int dx[4] = {1,0,0,-1};
	const int dy[4] = {0,1,-1,0};

	void dfs (vector<vector<int>>& image, int x, int y, int color, int newColor) {
		if (image[x][y] == color) {
			image[x][y] = newColor;
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i], my = y + dy[i];
				if (mx >= 0 && mx < image.size() && my >= 0 && my < image[0].size()) {
					dfs(image, mx, my, color, newColor);
				}
			}
		}
	}


public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int curColor = image[sr][sc];
		if (curColor != newColor) {
			dfs (image, sr, sc, curColor, newColor);
		}
		return image;
	}
};


/*
这种直接递归回溯，直接提交会出现栈溢出
*/
class Solution {
private:
	void dfs (vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& visited, int target) {
		if (image[sr][sc] == target) {
			image[sr][sc] = newColor;
		} else {
			return;
		}

		if (sc < 0 || sc >= image[0].size() || sc < 0 || sc >= image.size()) {
			return;
		}

		// 向左
		if (sr - 1 >= 0 && visited[sr - 1][sc] == false) {
			visited[sr - 1][sc] = true;
			dfs(image, sr - 1, sc, newColor, visited, target);
			visited[sr - 1][sc] = false;
		}
		// 向右
		if (sr + 1 < image[0].size() && visited[sr + 1][sc] == false) {
			visited[sr + 1][sc] = true;
			dfs(image, sr + 1, sc, newColor, visited, target);
			visited[sr + 1][sc] = false;
		}
		// 向上
		if (sc - 1 >= 0 && visited[sr][sc - 1] == false) {
			visited[sr][sc - 1] = true;
			dfs(image, sr, sc - 1, newColor, visited, target);
			visited[sr][sc - 1] = false;
		}
		// 向下
		if (sc + 1 < image.size() && visited[sr][sc + 1] == false) {
			visited[sr][sc + 1] = true;
			dfs(image, sr, sc + 1, newColor, visited, target);
			visited[sr][sc + 1] = false;
		}
	}

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<bool>> visited (image.size(), vector<bool>(image[0].size()));

		visited[sr][sc] = true;
		dfs (image, sr, sc, newColor, visited, image[sr][sc]);

		return image;
	}
};

int main_123246() {
	SolutionMethod sol;
	vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
	int sr = 1;
	int sc = 1;
	int newColor = 2;
	vector<vector<int>> res = sol.floodFill(image, sr, sc, newColor);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}
	cout << endl;

	image = {{0,0,0}, {0,0,0},{0,0,0}};
	sr = 1, sc = 1, newColor = 2;

	res = sol.floodFill(image, sr, sc, newColor);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}
