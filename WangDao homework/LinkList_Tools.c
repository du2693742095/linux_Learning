#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
	int val;
	struct Node_s* prior;
	struct Node_s* next;
} Node;

typedef struct List_s {
	int size;
	Node* head;
	Node* rear;
} LinkList;


//创建一个LinkList
LinkList* Create_LinkList() {
	return (LinkList*)calloc(1,sizeof(LinkList));
}

//销毁LinkList，并释放里面所有的元素
void Destroy_List(LinkList* list) {
	LinkList* p = list;
}

//插入的步骤：生成结点、链接、更新信息
//头插
void Add_Before_Head(LinkList* list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in Add_Befor_Head.\n");
		exit(1);
	}
	newNode->val = val;
	newNode->prior = NULL;
	newNode->next = list->head;
	//如果存在下一个结点，那就更新下一个结点的prior
	if (newNode->next != NULL) {
		newNode->next->prior = newNode;
	}
	if (list->rear == NULL) {
		list->rear = newNode;
	}
	list->head = newNode;
	list->size++;
}

//尾插法
void Add_After_Rear(LinkList* list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in Add_After_Rear.\n");
		exit(1);
	}
	newNode->val = val;
	newNode->next = NULL;
	newNode->prior = list->rear;
	if (newNode->prior != NULL) {
		newNode->prior->next = newNode;
	}
	if (list->head == NULL) {
		list->head = newNode;
	}
	list->rear = newNode;
	list->size++;
}

//任意地点插入
void Add_Node(LinkList* list, int index, int val) {
	if (index > list->size || index < 0) {
		printf("Error: Invalid argument in Add_Node\n");
		exit(1);
	}
	//若尾插
	if (index == list->size) {
		Add_After_Rear(list, val);
		return;
	}
	//若头插
	if (index == 0) { 
		Add_Before_Head(list, val);
		return;
	}
	//在中间插入
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in Add_Node.\n");
		exit(1);
	}
	newNode->val = val;
	Node* p = list->head;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	newNode->prior = p->prior;
	newNode->prior->next = newNode;
	newNode->next = p;
	p->prior = newNode;
	list->size++;
}

//删除某个值的第一个结点
void Delete_Node(LinkList* list, int val) {
	Node* p = list->head;
	while (p != NULL && p->val != val) {
		p = p->next;
	}
	if (p == NULL) return;
	//链接prior指针，特殊情况头节点
	if (p->prior == NULL) {
		list->head = p->next;
	}
	else {
		p->prior->next = p->next;
	}
	//链接next指针，特殊情况尾结点
	if (p->next == NULL) {
		list->rear = p->prior;
	}
	else {
		p->next->prior = p->prior;
	}
	free(p);
	list->size--;
	
}

//根据索引值查找list的结点的值
int Search_index(LinkList* list, int index) {
	if (index > list->size || index < 0) {
		printf("Error: Invalid argument in Search_index.\n");
		exit(1);
	}
	int val = 0;
	Node* p = list->head;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	return p->val;
}

//根据值查找list的索引
int Search2_val(LinkList* list, int val) {
	Node* p = list->head;
	int index = 0;
	while (p != NULL && p->val != val) {
		p = p->next;
		index++;
	}
	if (p == NULL) return -1;
	else return index;
}



//==========================================================
//链表简单算法

typedef struct node_s {
    int val;
    struct node_s* next;
} Node;

//用快慢指针查找链表中点
int middleElement(Node* list) {
	int index = 0;
	Node* fast = list;
	Node* slow = list;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		index++;
	}
	return index;
}

//用快慢指针查找是否有环
bool isRing_pointer(Node* list) {
	Node* fast = list;
	Node* slow = list;
	while (fast != NULL && fast->next != NULL) {
		if (fast == slow) {
			return true;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
}

//用迷雾森林法查找是否有环
#define Maxsize 250

bool isRing_forest(Node* list) {
	Node* isVisited[Maxsize] = { NULL };
	int i = 0;
	Node* p = list;
	while (p) {
		for (int j = 0; j < i; j++) {
			if (isVisited[j] == p) {
				return true;
			}
		}
		isVisited[i++] = p;
		p = p->next;
	}
	return false;
}

//反转链表
Node* reverse(Node* list) {
	if (list == NULL || list->next == NULL) return list;
	Node* cur = list->next;
	Node* pre = list;
	pre->next = NULL;
	while (cur) {
		Node* temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

//合并两个有序单链表
Node* mergeTwoLists(Node* list1, Node* list2) {
	Node head;
	Node* p = &head;
	Node* p1 = list1;
	Node* p2 = list2;
	while (p1 != NULL && p2 != NULL) {
		if (p1->val < p2->val) {
			p->next = p1;
			p = p->next;
			p1 = p1->next;
		}
		else {
			p->next = p2;
			p = p->next;
			p2 = p2->next;
		}
	}
	if (p1 != NULL) {
		p->next = p1;
	}
	else{
		p->next = p2;
	}
	return head.next;
}
