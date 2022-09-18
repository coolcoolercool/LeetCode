#include "../../include.h"

/**
 * 题目:
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/
 */

class Solution {
public:
	//反转字符串
	void reverse_ziji(string &s, int start, int end) {
		while (start < end) {
			swap(s[start++], s[end--]);
		}
	}

	//移除多余空格，利用快慢指针
	void removeExtraSpaces(string &s) {
		int slow = 0, fast = 0;
		//移除开始位置的空格
		while (s[fast] == ' ') {
			fast++;
		}
		//移除中间位置多余的空格
		while (fast < s.size()) {
			if (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ') {
				fast++;
			} else {
				s[slow] = s[fast];
				slow++;
				fast++;
			}
		}
		//如果末尾仅有一个空格，则上述无法将该空格移除；如果末尾有很多空格，则上述将保留一个空格，也不符合要求；所以最终可能的情况有二：末尾有一个空格/末尾无空格

		if (slow - 1 > 0 && s[slow - 1] == ' ') {
			slow--;
		}
		s.resize(slow);
	}

	string reverseWords(string s) {
		//step1.移除多余空格
		removeExtraSpaces(s);
		//step2.反转整个字符串
		reverse_ziji(s, 0, s.size() - 1);
		//step3.依次反转每个单词
		int start = 0; // 记录每个单词的起始位置
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				reverse_ziji(s, start, i - 1);
				start = i + 1;
			}
			if (i == s.size() - 1) {
				reverse_ziji(s, start, i);
			}
		}
		return s;
	}

	// 移除首尾部分多余的空格
	void removeSpace(string& s) {
		int left = 0, right = s.size() - 1;
		while(left <= right && s[left] == ' ') {
			left++;
		}
		while(left <= right && s[right] == ' ') {
			right--;
		}
		s = s.substr(left, right - left + 1);
	}

	// 移除字符串之间的空格
	void removeMidSpace(string& s) {
		int left = 0, right = 0, size = s.size();
		while(right < size) {
			if(right > 0 && s[right] == ' ' && s[right - 1] == ' ') {
				right++;
			} else {
				s[left] = s[right];
				left++, right++;
			}
		}
		s.resize(left);
	}

	void help(string& s, int left, int right) {
		while(left >= 0 && right < s.size() && right > left) {
			swap(s[left], s[right]);
			left++, right--;
		}
	}

	string reverseWords_easy_write(string s) {
		removeSpace(s);
		removeMidSpace(s);
		help(s, 0, s.size() - 1);
		int start = 0;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == ' ') {
				help(s, start, i - 1);
				start = i + 1;
			}
			if (i == s.size() - 1) {
				help(s, start, i);
			}
		}

		return s;
	}


	/*
	 * 一种没有用split 和reverse的方法
		分三步:
		先翻转整个数组
		再翻转单个单词
		清除多余空格
	 */
	string reverseWords_1(string s) {
		reverse(s.begin(), s.end());  // 反转整个数组
		int length = s.length();
		int index = 0;
		for (int start = 0; start < s.length(); start++) {
			if (s[start] != ' ') {
				// 填一个空白字符然后将idx移动到下一个单词的开头位置
				if (index != 0) {
					s[index] = ' ';
					index++;
				}

				// 循环遍历 到 单词的末尾
				int end = start;
				while (end < length && s[end] != ' ') {
					s[index] = s[end];
					index++;
					end++;
				}

				// 反转整个单词
				reverse(s.begin() + index - (end - start), s.begin() + index);

				// 更新 start, 开始处理下一个单词
				start = end;
			}
		}
		s.erase(s.begin() + index, s.end());
		return s;
	}

	/*
		双端队列
		思路和算法
		由于双端队列支持从队列头部插入的方法，因此我们可以沿着字符串一个一个单词处理，然后将单词压入队列的头部，再将队列转成字符串即可。

	    复杂度分析
		时间复杂度：O(n)，其中 n 为输入字符串的长度。
		空间复杂度：O(n)，双端队列存储单词需要 O(n) 的空间。
	 */
	string reverseWords_2(string s) {
		int left = 0, right = s.size() - 1;
		// 去掉字符串开头的空白字符
		while(left <= right && s[left] == ' ') left++;

		// 去掉字符串末尾的空白字符
		while(left <= right && s[right] == ' ') right--;

		deque<string> d;
		string word;

		while(left <= right) {
			char c = s[left];
			if (word.size() && c == ' ') {
				d.push_front(word);
				word = "";
			} else if (c != ' ') {
				word += c;
			}
			left++;
		}
		d.push_front(move(word));

		string ans;
		while(!d.empty()) {
			ans += d.front();
			d.pop_front();
			if(!d.empty()) ans += ' ';
		}

		return s;
	}



};

/*
 */






