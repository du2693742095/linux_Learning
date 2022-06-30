//写一个程序，实现分数相加。用户以分子/分母的形式输入分数，程序打印相加后的结果。

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Simplify(int data_first, int data_end) {
	int max = data_first > data_end ? data_first : data_end;
	int min = data_first > data_end ? data_end : data_first;
	int temp;
	while (min > 0) {
		temp = max % min;
		max = min;
		min = temp;
	}
	return max;
}

void Add_Fraction(int data_1_first, int data_1_end, int data_2_first, int data_2_end) {
	int result_first, result_end;
	if (data_1_end == data_2_end) {
		result_first = data_1_first + data_2_first;
		result_end = data_1_end;
	}
	else {
		result_first = data_1_first * data_2_end + data_2_first * data_1_end;
		result_end = data_1_end * data_2_end;
	}
	printf("The sum is %d/%d\n", result_first, result_end);
	int common = Simplify(result_first, result_end);
	printf("The simplifation is %d/%d\n", result_first / common, result_end / common);

}

int main() {
	int data_1_first, data_1_end;
	int data_2_first, data_2_end;

	printf("Enter first fraction: ");
	scanf("%d/%d", &data_1_first, &data_1_end);
	printf("Enter second fraction: ");
	scanf("%d/%d", &data_2_first, &data_2_end);

	Add_Fraction(data_1_first, data_1_end, data_2_first, data_2_end);

	return 0;
}
