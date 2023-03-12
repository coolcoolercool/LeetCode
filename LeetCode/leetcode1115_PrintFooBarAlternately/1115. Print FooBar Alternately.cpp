// Created by 周子望 on 2023/2/26.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/print-foobar-alternately/solutions/602913/c-3chong-fang-fa-yuan-zi-cao-zuo-tiao-ji-d2l9/

 1. 解法1
  使用原子变量作为线程执行的信号，如果不是 就让出时间片
 this_thread::yield相当于为忙等待提供了一个机会，可以主动让出线程的时间片，让os重新进行调度，但是下一个被调度进来的线程是哪个由os来决定，有可能是别的线程，也有可能还是当前线程。


**/
#include <bits/stdc++.h>
using namespace std;

// 使用原子操作
class FooBar_1 {
private:
	int n;
	atomic<bool> foo_done;

public:
	FooBar_1(int n) {
		this->n = n;
		foo_done = false;
	}

	void foo(function<void()> printFoo) {

		for (int i = 0; i < n; i++) {

			while(foo_done) {
				this_thread::yield();
			}

			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			foo_done = true;
		}
	}

	void bar(function<void()> printBar) {

		for (int i = 0; i < n; i++) {
			while(!foo_done) {
				this_thread::yield();
			}

			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			foo_done = false;
		}
	}
};