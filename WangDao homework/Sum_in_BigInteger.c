#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define Maxsize 100

void reverse(int a[],const int size) {
	for (int i = 0; i < size / 2; i++) {
		int temp = a[size - i - 1];
		a[size - i - 1] = a[i];
		a[i] = temp;
	}
}

void BigSum(char num1[], char num2[]) {
	int number_1[Maxsize] = { 0 };
	int number_2[Maxsize] = { 0 };
	int result[Maxsize];
	int size_1, size_2, size_r;
	//把字符串处理为int数组
	for (size_1 = 0; num1[size_1] != '\0'; size_1++) {
		number_1[size_1] = num1[size_1] - '0';
	}
	for (size_2 = 0; num2[size_2] != '\0'; size_2++) {
		number_2[size_2] = num2[size_2] - '0';
	}

	int size = size_1 > size_2 ? size_1 : size_2;
	reverse(number_1, size_1);
	reverse(number_2, size_2);

	int flag = 0;
	for (int i = 0; i < size; i++) {
		int temp = number_1[i] + number_2[i] + flag;
		if (temp >= 10) {
			flag = 1;
			result[i] = temp % 10;
		}
		else {
			result[i] = temp;
			flag = 0;
		}
	}
	if (flag) result[size++] = 1;
	reverse(result, size);

	puts("the resulte of sum is: ");
	for (int i = 0; i < size; i++) {
		printf("%d", result[i]);
	}
}

int main() {
	char a[Maxsize], b[Maxsize];
	puts("please inpute twe number: ");
	gets(a);
	gets(b);

	BigSum(a, b);

	return 0;
}
