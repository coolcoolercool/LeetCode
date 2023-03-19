#include "../../include.h"

class Solution {
public:
	unordered_map<char, char> mp = {
			{')', '('},
			{'}', '{'},
			{']', '['},
	};

	bool isValid(string s) {
		stack<char> st;
		for (auto element : s) {
			if (mp.count(element) == 0) { // ( { [
				st.push(element);
			} else { // ) } ]
				if (st.empty() || st.top() != mp[element]) return false;
				st.pop();
			}
		}
		return st.empty();  // 注意这个返回条件
	}

public:
	bool isValid_1(string s) {
		stack<char> stack;

		for (auto element : s) {
			if (element == '(' || element == '{' || element == '[') {
				stack.push(element);
			} else {
				if (stack.empty()) {
					return false;
				} else if (element == ')' && stack.top() != '(') {
					return false;
				} else if (element == '}' && stack.top() != '{') {
					return false;
				} else if (element == ']' && stack.top() != '[') {
					return false;
				}
				stack.pop();
			}
		}

		return stack.empty();
	}
};