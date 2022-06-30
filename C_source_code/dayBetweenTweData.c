// 输入某两天的年月日，输出这两天的相距多少天

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void ChangeArray(int a1[], int a2[],int b1[],int b2[]) {
	for (int i = 0; i < 3; i++) {
		b1[i] = a1[i];
		b2[i] = a2[i];
	}
}

bool isLeapYear(int i) {
	return (i % 4 == 0 && i % 100 != 0 || i % 400 == 0);
}

int Count_Day(int dayFirst[],int daySecond[]) {
	int month_day[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
	int count = 0;

	//判断哪一个是较大的日期,如果相等则默认第二个日期大
	int maxDay[3], minDay[3];
	if (dayFirst[0] > daySecond[0]) {
		ChangeArray(dayFirst, daySecond, maxDay, minDay);
	}
	else if(dayFirst[0] < daySecond[0]) {
		ChangeArray(dayFirst, daySecond, minDay, maxDay);
	}
	else {
		if (dayFirst[1] > daySecond[1]) {
			ChangeArray(dayFirst, daySecond, maxDay, minDay);
		}
		else {
			ChangeArray(dayFirst, daySecond, minDay, maxDay);
		}
	}

	//按年循环计数
	int year = maxDay[0] - minDay[0];
	//如果不满一年，则年数-1
	if (minDay[1] > maxDay[1]) {
		year--;
	}
	for (int i = 0; year > 0; i++) {
		if (isLeapYear(i)) {
			count += 365;
		}
		else{
			count += 366;
		}
		year--;
	}
	 
	//按月循环计数,遇到初始和后期有闰年的修改月份数组	(循环内其实多算了一个月）
	if (isLeapYear(maxDay[0]) || isLeapYear(minDay[0])) {
		month_day[2] = 29;
		if (minDay[1] < 2 && maxDay[1]>2) {
			count--;
		}
	}
	for (int i = minDay[1]; i != maxDay[1]; i = (i + 1) % 12) {
		count += month_day[i];
	}

	//计算天
	count += abs(maxDay[2] - minDay[2]);

	return count;
}

int main() {
	int day1[3];
	int day2[3];
	scanf("%d/%d/%d", &day1[0], &day1[1], &day1[2]);
	scanf("%d/%d/%d", &day2[0], &day2[1], &day2[2]);
	printf("%d\n",Count_Day(day1, day2));
	return 0;
}
