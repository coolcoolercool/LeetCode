#include "../../include.h"

class Solution {
public:
	unordered_map<char, char> innerMap = {
			{'(', '('},
			{'}', '{'},
			{']', '['},
			};

	bool isValid(string s) {
		stack<char> innerStack;
		for(auto element : s) {
			if (innerMap.count(element) == 0) { // ( { [
				innerStack.push(element);
			} else { // ) } ]
				if (innerStack.empty() || innerStack.top() != innerMap[element]) return false;
				innerStack.pop();
			}
		}
		return innerStack.empty();  // 注意这个返回条件
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