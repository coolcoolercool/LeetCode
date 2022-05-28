// Created by 周子望 on 2021/11/10

/*
 题目: 单词搜索
 给定一个m x n 二维字符网格board 和一个字符串单词word 。如果word 存在于网格中，返回 true ；否则，返回 false 。
 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 */

#include "../../include.h"

// 这种方法和我的基本没有差别，主要是它这个向四个方向遍历手法可以学习下
class Solution_Method {
public:
	bool flag = false;

	void
	help(vector<vector<char>> &board, string &word, int curX, int curY, int strIndex, vector<vector<bool>> &visited) {
		if (strIndex == word.size() - 1) {
			flag = true;
			return;
		}

		visited[curX][curY] = true;
		vector<pair<int, int>> dire = {{1,  0},
		                               {-1, 0},
		                               {0,  1},
		                               {0,  -1}};
		for (int i = 0; i < dire.size(); i++) {
			int newX = curX + dire[i].first, newY = curY + dire[i].second;
			if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && visited[newX][newY] == false
			    && strIndex + 1 < word.size() && board[newX][newY] == word[strIndex + 1]) {
				help(board, word, newX, newY, strIndex + 1, visited);
				if (flag) break;
			}
		}
		visited[curX][curY] = false;
	}


	bool exist(vector<vector<char>>& board, string word) {
		int rows = board.size(), cols = board[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (board[i][j] == word[0]) {
					help(board, word, i, j, 0, visited);
					if (flag) return flag;
				}
			}
		}

		return false;
	}
};


class Solution {
public:
	bool is_exist = false;
private:
	void dfs (vector<vector<char>>& board, string word, size_t cur_index, char cur_char, int begin_x, int begin_y, int rows, int cols, vector<vector<bool>>& visited) {
		if (cur_index == word.size() - 1 && cur_char == word[word.size() - 1]) {
			is_exist = true;
			return;
		}

		// 向上
		if (begin_x - 1 >= 0 && begin_y < cols && begin_x < rows && begin_y >= 0
			&& cur_index + 1 < word.size() && board[begin_x - 1][begin_y] == word[cur_index + 1]
			&& !visited[begin_x - 1][begin_y]) {
			//cout << "向上之前 res: " << is_exist << ", cur position: <" << begin_x - 1 << "," << begin_y << ">" << endl;
			visited[begin_x - 1][begin_y] = true;
			dfs(board, word, cur_index + 1, word[cur_index + 1], begin_x - 1, begin_y, rows, cols, visited);
			visited[begin_x - 1][begin_y] = false;
		}

		// 向下
		if (begin_x >= 0 && begin_y < cols && begin_x + 1 < rows && begin_y >= 0
		    && cur_index + 1 < word.size() && board[begin_x + 1][begin_y] == word[cur_index + 1]
		    && !visited[begin_x + 1][begin_y]) {
			//cout << "向下之前 res: " << is_exist << ", cur position: <" << begin_x + 1 << "," << begin_y << ">" <<  endl;

			visited[begin_x + 1][begin_y] = true;
			dfs(board, word, cur_index + 1, word[cur_index + 1], begin_x + 1, begin_y, rows, cols, visited);
			visited[begin_x + 1][begin_y] = false;
		}

		// 向左
		if (begin_x >= 0 && begin_y < cols && begin_x < rows && begin_y - 1 >= 0
		    && cur_index + 1 < word.size() && board[begin_x][begin_y - 1] == word[cur_index + 1]
		    && !visited[begin_x][begin_y - 1]) {
			//cout << "向左之前 res: " << is_exist << ", cur position: <" << begin_x << "," << begin_y - 1 << ">" <<  endl;
			visited[begin_x][begin_y - 1] = true;
			dfs(board, word, cur_index + 1, word[cur_index + 1], begin_x, begin_y - 1, rows, cols, visited);
			visited[begin_x][begin_y - 1] = false;
		}

		// 向右
		if (begin_x >= 0 && begin_y + 1 < cols && begin_x < rows && begin_y >= 0
		    && cur_index + 1 < word.size() && board[begin_x][begin_y + 1] == word[cur_index + 1]
		    && !visited[begin_x][begin_y + 1]) {
			//cout << "向右之前 res: " << is_exist << ", cur position: <" << begin_x << "," << begin_y + 1 << ">" <<  endl;
			visited[begin_x][begin_y + 1] = true;
			dfs(board, word, cur_index + 1, word[cur_index + 1], begin_x, begin_y + 1, rows, cols, visited);
			visited[begin_x][begin_y + 1] = false;
		}

		return;
	}

public:
	bool exist(vector<vector<char>>& board, string word) {
		int rows = board.size(), cols = board[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols));

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (board[i][j] == word[0]) {
					//cout << "begin position: <" << i << "," << j << ">" << endl;

					visited[i][j] = true;
					dfs(board, word, 0, word[0], i, j, rows, cols, visited);
					visited[i][j] = false;
					if (is_exist) {
						return true;
					}
				}
			}
		}

		return false;
	}
};

int main_imnj65 () {
	Solution sol;
	vector<vector<char>> board;
	string word;
	bool res;


	board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	word = "ABCCED";
	res = sol.exist(board, word);
	if (res) {
		cout << "res: " << "true" << endl;
	} else {
		cout << "res: " << "false" << endl;
	}
	cout << endl;

	sol.is_exist = false;
	board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	word = "SEE";
	res = sol.exist(board, word);
	if (res) {
		cout << "res: " << "true" << endl;
	} else {
		cout << "res: " << "false" << endl;
	}
	cout << endl;


	sol.is_exist = false;
	board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	word = "ABCB";
	res = sol.exist(board, word);
	if (res) {
		cout << "res: " << "true" << endl;
	} else {
		cout << "res: " << "false" << endl;
	}

	sol.is_exist = false;
	board = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
	word = "AAB";
	res = sol.exist(board, word);
	if (res) {
		cout << "res: " << "true" << endl;
	} else {
		cout << "res: " << "false" << endl;
	}


	return 0;
}

























