// Created by rainyzwzhou on 2022/4/24.

#include "../../include.h"

/**
用 Rand7() 实现 Rand10()

 核心思想:
 拒绝采样
思路与算法
我们可以用拒绝采样的方法实现 Rand10()。在拒绝采样中，如果生成的随机数满足要求，那么就返回该随机数，否则会不断生成，直到生成一个满足要求的随机数为止。

我们只需要能够满足等概率的生成 10 个不同的数即可，具体的生成方法可以有很多种，比如我们可以利用两个 Rand7() 相乘，我们只取其中等概率的 10 个不同的数的组合即可，当然还有许多其他不同的解法，可以利用各种运算和函数的组合等方式来实现。

题目中要求尽可能的减少 Rand7() 的调用次数，则我们应该尽量保证生成的每个不同的数的生成概率尽可能的大，即调用 Rand7() 期望次数尽可能的小。
我们可以调用两次 Rand7()，那么可以生成 [1, 49]之间的随机整数，我们只用到其中的前 40 个用来实现 Rand10()，而拒绝剩下的 9 个数

(randX() - 1)*Y + randY() 可以等概率的生成[1, X * Y]范围的随机数
证明: rand()7能等概率生成1~7； rand7() - 1能等概率生成0~6； (rand7() - 1) * 7能等概率生成{0, 7, 14, 21, 28, 35, 42}； (rand7() - 1) * 7 + rand7()能等概率生成1~49。
 */

class LeetCode470 {
public:
	/**
	 * 感觉第一份代码当成模拟 7 进制好理解些，把 rand7() 的值减 1 ，就成了 [0, 6]，模拟两位的 7 进制数，取 [0, 39] 范围内的值，对 10 取余后加一
	 * @return
	 */
	int rand7();
	int rand10() {
		int x, y, ans;
		do {
			x = rand7();
			y = rand7();
			ans = (x - 1) * 7 + (y - 1);
		} while(ans >= 40);
		return 1 + ans % 10;
	}

	/**
	 	rand7() 构造 rand10()
		构造 2 次采样，分别有 2 和 5 种结果，组合起来便有 10 种概率相同的结果。
		把这 10 种结果映射到 [1,10] 即可。
		第一步具体要如何构造采样是自由的，比如 rand7()拒绝 7，然后对 [1,6] 采样，把奇数和偶数作为 2 种结果，这 2 种结果的概率均为 0.5 。rand7() 拒绝 6,7 ，然后对 [1,5] 采样，有 5 种结果，每种概率均为 0.2 。
	 */
	int rand10_2() {
		int first, second;
		while ((first = rand7()) > 6); // 取 {1, 6}, //为什么不是{1,2},因为可以减少调用rand7()次数
		while ((second = rand7()) > 5); // 取 {1, 5}
		return (first & 1) == 1 ? second : 5 + second; // first 是奇数，就直接返回second；first是偶数，就返回 5+second
	}

	/**
		rand11()：
		构造 2 次采样，分别有 2 和 6 种结果，组合起来便有 12 种概率相同的结果。
		把这 12 种结果映射到 [1,12] ，然后再拒绝 12 即可。
	 */
	int rand11() {
		int first, second, ans;
		bool flag = true;
		while(flag) {
			while((first = rand7()) > 6); // 取 {1, 6}
			while((second == rand7()) > 6); // 取 {1, 6}

			ans = (first & 1) == 1 ? second : 6 + second;

			if(ans != 12) {
				flag = false;
			}
		}
		return ans;
	}

	/**
		rand100() ：
		构造 3 次采样，分别有 4,5,5 种结果，组合起来便有 100 种概率相同的结果。
		把这 100 种结果映射到 [1,100] 即可。
	*/
	int rand100() {
		int first, second, ans;
		while(true) {
			while((first = rand7()) > 6); // 取 {1, 2}
			while((second == rand7()) > 6); // 取 {1, 6}

			ans = (first & 1) == 1 ? second : 6 + second;

			if(ans != 12) {
				return ans;
			}
		}
	}

	/**
	 * 来个左神的万能解法： 把已知的范围按等概率划分，分别返回0和1。 然后通过0和1组合得到任意范围的结果。
		此题范围1-7，可以划分为生成1,2,3时返回0，生成5,6,7返回1，随机到4就重新生成。 1-10的范围可以表示成1 + (0到9) 二进制的0000-1111范围为0-15，如果范围超过了9就重新生成。 一定可以返回一个0-9的数
	 */
	 int get0Or1() {
	 	int random = rand7();
	 	while(true) {
	 		if (random < 4) {
	 			return 0;
	 		} else if (random > 4) {
	 			return 1;
	 		} else { // random = 4
	 			random = rand7();
	 		}
	 	}
	 }

	 int rand10_zuo(){
	 	int res;
	 	do {
	 		res = (get0Or1() << 3) + (get0Or1() << 2) + (get0Or1() << 1) + get0Or1();
	 	} while(res > 9);
	 	return res + 1;
	 }

	 int rand100_zuo(){
	 	int res;
	 	do {
	 		res = (get0Or1() << 8) + (get0Or1() << 7)  +  (get0Or1() << 6) + (get0Or1() << 5) + (get0Or1() << 4) + (get0Or1() << 3) + (get0Or1() << 2) + (get0Or1() << 1) +
	 				+ get0Or1();
	 	} while(res > 100);
	 	return res + 1;
	 }


};