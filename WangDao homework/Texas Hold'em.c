//德州扑克：写一个程序循环读取 5 张手牌 (输入 0 结束程序)，然后把手中的牌分为下面某一类：
//1.同花顺 2.四张 3.葫芦 (3 + 2) 4. 同花 5. 顺子  6.三张 7.两对 8. 一对 9.高牌

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char color_correct[4] = { 's','c','d','h' };
char num_correct[13] = { '2','3','4','5','6','7','8','9','t','j','q','k','a' };
int num_sort[5] = { 0 };	//用来存入牌的大小，排序用
char color[5];	//存颜色

void swap(int a[], int a_num, int b_num);
void BobSort(int a[],int size);
void GetHandCard();
void Classify();

int main() {
	char num[5];
	GetHandCard(num, color);
	Classify();

	return 0;
}

//交换数组中的两个值
void swap(int a[],int a_num,int b_num) {
	a[a_num] = a[a_num] ^ a[b_num];
	a[b_num] = a[a_num] ^ a[b_num];
	a[a_num] = a[a_num] ^ a[b_num];
}

//冒泡排序
void BobSort(int a[],int size) {
	int same = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a,j,j+1);
			}
		}
	}
}

//获取手牌，并判断输入是否合法
void GetHandCard() {
	int i = 0;
	char num[5];
	while (i < 5) {
		char n, c;
		
		//遇到重复的，就跳转重新来
	again:
		scanf("%c%c", &n, &c);
		getchar();	//读入空白字符

		//判断牌是否越界
		int numCheck, colorCheck;
		for (numCheck = 0; numCheck < 13; numCheck++) {
			if (n == num_correct[numCheck]) {
				break;
			}
		}
		for (colorCheck = 0; colorCheck < 4; colorCheck++) {
			if (c == color_correct[colorCheck]) {
				break;
			}
		}
		if (numCheck == 13 || colorCheck == 4) {
			printf("Bad card; ignored.\n");
			continue;
		}

		//判断是否重复
		int j = 0;
		while (j < i) {
			if (n == num[j] && c == color[j]) {
				printf("Duplicate card; ignored.\n");
				goto again;
			}
			j++;
		}

		//判断完以后，把数字存入另一个数组,用来排序
		num_sort[i] = numCheck;
		num[i] = n;
		color[i] = c;
		i++;
	}
}

//输出手牌的牌型
void Classify() {
	BobSort(num_sort,5);	//排序
	int flag = 0;	//一对，两对，三条，葫芦，四对，顺子，同花，同花顺
	int check;	//用作循环比较，如果能循环出来，就说明循环内条件不满足

	//顺子
	for (check = 0; check < 4; check++) {
		if (num_sort[check] != num_sort[check + 1] - 1) {
			break;
		}
	}
	if (check == 4) flag = 6;

	//判断初同花外的其余牌型
	int temp[13] = { 0 }; //temp数组用作统计相同的字符数，下标表示数字，内存表示出现次数
	for (int i = 0; i < 4; i++) {
		if (num_sort[i + 1] == num_sort[i]) {
			temp[num_sort[i]]++;
		}
	}
	int pairs_num = 0;	//1为1对，2为2对，3为3条，葫芦为5，四对为6
	for (int i = 0; i < 13; i++) {
		if (temp[i] == 1) pairs_num++;
		if (temp[i] == 2) pairs_num += 3;
		if (temp[i] == 3) pairs_num += 6;
	}
	switch (pairs_num){
	case 1:
		flag = 1;	//一对
		break;
	case 2:
		flag = 2; //二对
		break;
	case 3:
		flag = 3; //三对
		break;
	case 5:
		flag = 4; //葫芦
		break;
	case 6:
		flag = 5; //四对
		break;
	default:
		break;
	}
	
	//判定同花
	check = 0;
	for (int i = 0; i < 4; i++) {
		if (color[i] != color[i + 1]) {
			check = 1;
			break;
		}
	}
	if (check == 0) {
		if (flag == 6) {
			flag = 8;
		}
		else{
			flag = 7;
		}
	}

	//输出：一对，两对，三条，葫芦，四对，顺子，同花，同花顺
	switch (flag)
	{
	case 1:
		printf("Pair\n");
		break;
	case 2:
		printf("TwoPairs\n");
		break;
	case 3:
		printf("Threeofakind\n");
		break;
	case 4:
		printf("Fullhouse\n");
		break;
	case 5:
		printf("FourPair\n");
		break;
	case 6:
		printf("Straight\n");
		break;
	case 7:
		printf("Flush\n");
		break;
	case 8:
		printf("RoyalFlush\n");
		break;
	default:
		printf("high card\n");
		break;
	}
}
