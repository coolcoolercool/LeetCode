#include "../../include.h"

/**
 * 题目:
 * https://leetcode-cn.com/problems/lru-cache/
 */

/*
 * 思路：
保持把新鲜数据往链表头移动。新鲜的定义：刚被修改(put)，或者访问过(get)，就算新鲜，就需要 splice 到链表头。
过期键直接 pop_back()，链表节点越往后，越陈旧。

代码要领：
map 中保存的是 <key, 链表节点的指针>，这样查找的时候就不用需要去遍历链表了，使用 unordered_map 就能很快找到链表节点指针。
判断容量的时候，最好不使用 std::list::size() 方法，在 c++ 里，这个方法可能不是 O(1) 的。
 */

class LRUCache {
public:
	LRUCache(int capacity) : capacity(capacity) {}

	int get(int key) {
		if (innerMap.find(key) != innerMap.end()) {
			auto key_value = *innerMap[key];
			innerList.erase(innerMap[key]);
			innerList.push_front(key_value);

			innerMap[key] = innerList.begin();
			return key_value.second;
		}
		return -1;
	}

	void put(int key, int value) {
		if (innerMap.find(key) == innerMap.end()) {
			if (list_size == capacity) {
				innerMap.erase(innerList.back().first);
				innerList.pop_back();
				list_size--;
			}
		} else {
			innerList.erase(innerMap[key]);
			list_size--;
		}

		innerList.push_front({key, value});
		list_size++;
		innerMap[key] = innerList.begin();
	}

private:
	map<int, list<pair<int, int>>::iterator> innerMap; // map 保存的
	int capacity = 0;
	list<pair<int, int>> innerList;  // 双端链表
	int list_size = 0;
};

/*
 * 会超时，不满足下面这点
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 */
class LRUCacheKeyValue {
public:
	LRUCacheKeyValue(int capacity) : capacity(capacity) {}

	int get(int key) {
		if (inner_map.find(key) != inner_map.end()) {
			inner_list.remove(key);
			inner_list.push_front(key);
			return inner_map[key];
		}
		print_list(&inner_list);
		return -1;
	}

	void put(int key, int value) {
		if (inner_map.find(key) == inner_map.end()) {
			if (inner_list.size() == capacity) {
				inner_map.erase(inner_list.back());
				inner_list.pop_back();
			}
		} else {
			inner_list.remove(key);
		}

		inner_list.push_front(key);
		inner_map[key] = value;
		print_list(&inner_list);
	}

private:
	map<int, int> inner_map;
	int capacity = 0;
	list<int> inner_list;  // 双端链表
};


int main_ok87nm() {
	LRUCacheKeyValue* lru = new LRUCacheKeyValue(2);
	lru->put(1,1);
	lru->put(2,2);
	lru->get(1);
	lru->put(3,3);
	lru->get(2);
	lru->put(4,4);
	lru->get(1);
	lru->get(3);
	lru->get(4);

	return 0;
}
/*
 */






