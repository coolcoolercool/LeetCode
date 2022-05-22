// Created by 周子望 on 2021/10/31

/*
题目:
 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母都恰好只用一次。

核心思想:
 两个字符串互为字母异位词，当且仅当两个字符串包含的字母相同。同一组字母异位词中的字符串具备相同点，可以使用相同点作为一组字母异位词的标志，使用哈希表存储每一组字母异位词，
 哈希表的键为一组字母异位词的标志，哈希表的值为一组字母异位词列表。
遍历每个字符串，对于每个字符串，得到该字符串所在的一组字母异位词的标志，将当前字符串加入该组字母异位词的列表中。遍历全部字符串之后，哈希表中的每个键值对即为一组字母异位词。
以下的两种方法分别使用排序和计数作为哈希表的键。

 */

#include "../../include.h"

class Solution_Method {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> hash;

		for (string &s:strs) {
			string tmp = s;
			sort(tmp.begin(), tmp.end());       //将当前单词内的字母排序
			hash[tmp].push_back(s);             //将原始单词存入属于它的异位词组中
		}                                       //hash[oneRes]表示tmp这组异位词的集合

		for (auto &vec : hash) {  		//遍历哈希表，将值存入结果集中
			res.push_back(vec.second);
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> map;

		for (int i = 0; i < strs.size(); i++) {
			string temp_str = strs[i];
			sort(temp_str.begin(), temp_str.end());

			map[temp_str].push_back(strs[i]);
		}

		vector<vector<string>> res;
		for (auto element : map) {
			res.push_back(element.second);
		}
		return res;
	}

}; // class

int main_21lkm() {
	Solution_Method sol;
	vector<string> strs = {"", ""};

	vector<vector<string>> res = sol.groupAnagrams(strs);

	cout << "size : " << res.size() << endl;
	print_vector_vector(res);

	return 0;
}