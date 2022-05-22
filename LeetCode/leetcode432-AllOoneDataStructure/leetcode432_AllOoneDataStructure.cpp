//
// Created by rainyzwzhou on 2022/4/27.
//

/**
本题要求每次操作的时间复杂度均为 O(1)O(1)（字符串长度视作常数）。我们可以结合双向链表和哈希表来实现，具体如下：

链表中的每个节点存储一个字符串集合 keys，和一个正整数 count，表示 keys 中的字符串均出现 count 次。链表从头到尾的每个节点的 count 值单调递增（但不一定连续）。此外，每个节点还需存储指向上一个节点的指针 prev 和指向下一个节点的指针 next。

另外还要用一个哈希表 nodes 维护每个字符串当前所处的链表节点。

对于 inc 操作：

若 key 不在链表中：若链表为空或头节点的 count>1，则先插入一个 =1count=1 的新节点至链表头部，然后将 key 插入到头节点的 keys 中。
若 key 在链表中：设 key 所在节点为 cur，若 .cur.next 为空或 ..>.+1cur.next.count>cur.count+1，则先插入一个 =.+1count=cur.count+1 的新节点至 cur 之后，然后将 key 插入到 ..cur.next.keys 中。最后，将 key 从 .cur.keys 中移除，若移除后 .cur.keys 为空，则将 cur 从链表中移除。
更新 nodes 中 key 所处的节点。
对于 {dec}dec 操作，测试用例保证 key 在链表中。

若 key 仅出现一次：将其从 nodes 中移除。
若 key 出现不止一次：设 key 所在节点为 cur，若 .cur.prev 为空或 ..<.-1cur.prev.count<cur.count−1，则先插入一个 =.-1count=cur.count−1 的新节点至 cur 之前，然后将 key 插入到 ..cur.prev.keys 中。更新 nodes 中 key 所处的节点。
最后，将 key 从 .cur.keys 中移除，若移除后 .cur.keys 为空，则将 cur 从链表中移除。
对于 getMaxKey 操作，在链表不为空时，返回链表尾节点的 keys 中的任一元素，否则返回空字符串。

 */

#include "../../../LeetCode/include.h"

#include <unordered_set>
class AllOne {
	list<pair<unordered_set<string>, int>> lst;
	unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodes;

public:
	AllOne() {}

	void inc(string key) {
		if (nodes.count(key) == 1) {
			auto cur = nodes[key], nxt = next(cur);
			if (nxt == lst.end() || nxt->second > cur->second + 1) {
				unordered_set<string> s({key});
				nodes[key] = lst.emplace(nxt, s, cur->second + 1);
			} else {
				nxt->first.emplace(key);
				nodes[key] = nxt;
			}
			cur->first.erase(key);
			if (cur->first.empty()) {
				lst.erase(cur);
			}
		} else { // key 不在链表中
			if (lst.empty() || lst.begin()->second > 1) {
				unordered_set<string> s({key});
				lst.emplace_front(s, 1);
			} else {
				lst.begin()->first.emplace(key);
			}
			nodes[key] = lst.begin();
		}
	}

	void dec(string key) {
		auto cur = nodes[key];
		if (cur->second == 1) { // key 仅出现一次，将其移出 nodes
			nodes.erase(key);
		} else {
			auto pre = prev(cur);
			if (cur == lst.begin() || pre->second < cur->second - 1) {
				unordered_set<string> s({key});
				nodes[key] = lst.emplace(cur, s, cur->second - 1);
			} else {
				pre->first.emplace(key);
				nodes[key] = pre;
			}
		}
		cur->first.erase(key);
		if (cur->first.empty()) {
			lst.erase(cur);
		}
	}

	string getMaxKey() {
		return lst.empty() ? "" : *lst.rbegin()->first.begin();
	}

	string getMinKey() {
		return lst.empty() ? "" : *lst.begin()->first.begin();
	}
};

