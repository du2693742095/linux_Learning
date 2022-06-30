//给定一个整数数组，里面的数都是成对出现的，只有两个数例外，请写程序找出这个两个数。

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Find(int a[]) {
	int xor = 0;
	for (int i = 0; i < 8; i++) {
		xor ^= a[i];
	}

	int check = xor &(-xor);

	int b1[8] = { 0 }, b2[8] = { 0 };
	int i = 0, j = 0;
	for (int m = 0; m < 8; m++) {
		if (check & a[m]) {
			b1[i++] = a[m];
		}
		else {
			b2[j++] = a[m];
		}
	}

	int result1 = 0, result2 = 0;
	for (int i = 0; i < 8; i++) {
		result1 ^= b1[i];
	}
	for (int i = 0; i < 8; i++) {
		result2 ^= b2[i];
	}
	printf("%d %d", result1, result2);
}

int main() {
	int a[] = { 10,22,22,33,33,41,41,6 };
	Find(a);
	return 0;
}
