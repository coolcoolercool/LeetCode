// Created by 周子望 on 2023/2/26.

/**
题目描述:

核心思想:
**/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mtx;
int turn = 0;
bool runFlag = true;
int cnt = 0;

void* threadA(void* args) {
	while (runFlag) {
		pthread_mutex_lock(&mtx);
		if (turn == 0) {
			printf("A\n");
			turn = 1;
		}
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}

void* threadB(void* args) {
	while (runFlag) {
		pthread_mutex_lock(&mtx);
		if (turn == 1) {
			printf("B\n");
			turn = 2;
		}
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}

void* threadC(void* args) {
	while (runFlag) {
		pthread_mutex_lock(&mtx);
		if (turn == 2) {
			printf("C\n");
			turn = 0;

			cnt++;
			if (cnt == 2) {
				runFlag = false;
			}

		}
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}

int main_ok98jn() {
	pthread_t tA, tB, tC;
	pthread_mutex_init(&mtx, NULL);
	pthread_create(&tA, NULL, threadA, NULL);
	pthread_create(&tB, NULL, threadB, NULL);
	pthread_create(&tC, NULL, threadC, NULL);
	while (1) sleep(1);

	return 0;
}