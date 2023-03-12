// Created by 周子望 on 2023/2/26.

/**
题目描述:
三个线程，线程A输出A， 线程B输出B， 线程C输出C，
三个线程打印ABC， 打印十次， 输出 ABCABCABCABCABCABCABCABCABCABCABC


核心思想:
https://juejin.cn/s/%E4%B8%89%E4%B8%AA%E7%BA%BF%E7%A8%8B%E5%A6%82%E4%BD%95%E5%AE%9E%E7%8E%B0%E4%BA%A4%E6%9B%BF%E6%89%93%E5%8D%B0ABC%20c%E8%AF%AD%E8%A8%80

 使用C++11的标准线程语法，用一个变量控制条件变量的wait()阻塞等待时机，用notify_all()唤醒条件变量。
**/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>
#include <algorithm>
#include <functional>

std::mutex mtxlock;
std::condition_variable cvar;
char g_ch = 0;

void print_fun(char ch) {
	int cycle_cnt = 10;
	char ch_ = ch - 'A';

	for (int i = 0; i < cycle_cnt; i++) {
		std::unique_lock<std::mutex> ulk(mtxlock);
		cvar.wait(ulk, [ch_] { return ch_ == g_ch; });
		std::cout << (char)(ch_ + 'A');
		g_ch = (ch_ + 1) % 3;
		ulk.unlock();

		cvar.notify_all();
	}
}

int main_0omn76() {
	std::vector<std::thread> threads_vec;
	threads_vec.push_back(std::thread(print_fun, 'A'));
	threads_vec.push_back(std::thread(print_fun, 'B'));
	threads_vec.push_back(std::thread(print_fun, 'C'));
	std::for_each(threads_vec.begin(), threads_vec.end(), std::mem_fn(&std::thread::join));

	std::cout << std::endl;
	system("pause");
	return 0;
}