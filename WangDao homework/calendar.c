/*
输入1970年之后任意一年的年份，输出该年的年历。
输入：
Please input the year whose calendear you want to know?
2004
输出：
|=====================The Calendar of Year 2004====================|
:  1  SUN MON TUE WED THU FRI SAT   7  SUN MON TUE WED THU FRI SAT :
:                       1   2   3                        1   2   3 :
:       4   5   6   7   8   9  10        4   5   6   7   8   9  10 :
:      11  12  13  14  15  16  17       11  12  13  14  15  16  17 :
:      18  19  20  21  22  23  24       18  19  20  21  22  23  24 :
:      25  26  27  28  29  30  31       25  26  27  28  29  30  31 :
:  2  SUN MON TUE WED THU FRI SAT   8  SUN MON TUE WED THU FRI SAT :
:       1   2   3   4   5   6   7        1   2   3   4   5   6   7 :
:       8   9  10  11  12  13  14        8   9  10  11  12  13  14 :
:      15  16  17  18  19  20  21       15  16  17  18  19  20  21 :
:      22  23  24  25  26  27  28       22  23  24  25  26  27  28 :
:      29                               29  30  31                 :
:  3  SUN MON TUE WED THU FRI SAT   9  SUN MON TUE WED THU FRI SAT :
:           1   2   3   4   5   6                    1   2   3   4 :
:       7   8   9  10  11  12  13        5   6   7   8   9  10  11 :
:      14  15  16  17  18  19  20       12  13  14  15  16  17  18 :
:      21  22  23  24  25  26  27       19  20  21  22  23  24  25 :
:      28  29  30  31                   26  27  28  29  30         :
:  4  SUN MON TUE WED THU FRI SAT  10  SUN MON TUE WED THU FRI SAT :
:                       1   2   3                            1   2 :
:       4   5   6   7   8   9  10        3   4   5   6   7   8   9 :
:      11  12  13  14  15  16  17       10  11  12  13  14  15  16 :
:      18  19  20  21  22  23  24       17  18  19  20  21  22  23 :
:      25  26  27  28  29  30           24  25  26  27  28  29  30 :
:                                       31                         :
:  5  SUN MON TUE WED THU FRI SAT  11  SUN MON TUE WED THU FRI SAT :
:                               1            1   2   3   4   5   6 :
:       2   3   4   5   6   7   8        7   8   9  10  11  12  13 :
:       9  10  11  12  13  14  15       14  15  16  17  18  19  20 :
:      16  17  18  19  20  21  22       21  22  23  24  25  26  27 :
:      23  24  25  26  27  28  29       28  29  30                 :
:      30  31                                                      :
:  6  SUN MON TUE WED THU FRI SAT  12  SUN MON TUE WED THU FRI SAT :
:               1   2   3   4   5                    1   2   3   4 :
:       6   7   8   9  10  11  12        5   6   7   8   9  10  11 :
:      13  14  15  16  17  18  19       12  13  14  15  16  17  18 :
:      20  21  22  23  24  25  26       19  20  21  22  23  24  25 :
:      27  28  29  30                   26  27  28  29  30  31     :
|==================================================================|
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int i);
void print(int day);
int Count_Day(int day[]);
int isWeek(int day[]);
int Print_Calendar(int year);

//标记月份数组，作为全局变量
int month_day[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
	int year;
	printf("Please input the year whose calendear you want to know?\n");
	scanf("%d", &year);
	Print_Calendar(year);
	return 0;
}

bool isLeapYear(int i) {
	return ( i % 400 == 0 || i % 4 == 0 && i % 100 != 0);
}

int Count_Day(int day[]) {
	int count = 0;

	for (int i = day[0]; i > 1970; --i) {
		if (isLeapYear(i - 1)) {
			count += 366;
		}
		else {
			count += 365;
		}
	}

	for (int i = 1; i < day[1]; ++i) {
		count += month_day[i];
	}
	if (day[1] > 2 && isLeapYear(day[0]))	count++;

	count += day[2] - 1;	//因为是从1月1号开始，需要减一天

	return count;
}

//第一天是周日，把周四的数组下标改为为4
int isWeek(int day) {
	return (day + 4) % 7;
}

int Print_Calendar(int year) {
	printf("|======================The Calendar of Year %d====================|\n",year);

	//对12个月分为6个块进行打印
	for (int block = 0; block < 6; ++block) {
		printf(": %2d  SUN MON TUE WED THU FRI SAT  %2d  SUN MON TUE WED THU FRI SAT  :\n", block + 1, block + 7);
		int lineEnd_l = 1, lineEnd_r = 1;
		int day_l[] = { year,block + 1,1 };
		int day_r[] = { year,block + 7,1 };
		int totalDay_l = Count_Day(day_l);
		int totalDay_r = Count_Day(day_r);

		//每个月有5行需要输出
		for (int line = 0; line < 5; ++line) {
			//flag作标记位，每行有16个输出数字的位置，第0位和8位始终置0，其余位置不为0则输出数字
			int flag[16] = { 0 };
			
			//标记第一行和其它行，用lineEnd_l和r作为整体的日期统计
			if (line == 0) {
				int monthFirstday_l = isWeek(totalDay_l) + 1;
				int monthFirstday_r = isWeek(totalDay_r) + 1;
				for (int stringStation = monthFirstday_l; stringStation < 8; ++stringStation) {
					flag[stringStation] = lineEnd_l++;
				}
				for (int stringStation = monthFirstday_l + 8; stringStation < 16; ++stringStation) {
					flag[stringStation] = lineEnd_r++;
				}
			}
			else {
				for (int stringStation = 1; stringStation < 8; ++stringStation) {
					flag[stringStation] = lineEnd_l++;
					if (lineEnd_l > month_day[block + 1]) {
						break;
					}
				}
				for (int stringStation = 9; stringStation < 16; ++stringStation) {
					flag[stringStation] = lineEnd_r++;
					if (lineEnd_r > month_day[block + 7]) {
						break;
					}a
				}
			}

			//打印
			printf(":  ");
			for (int stringStation = 0; stringStation < 16; ++stringStation) {
					//2 space
				if (flag[stringStation] == 0) {
					printf("    "); //4 space
				}
				else {
					printf("%2d", flag[stringStation]);
					printf("  ");	//2 space
				}
			}
			printf(" :\n");
			
		}	
	}
	printf("|=================================================================|");
}
