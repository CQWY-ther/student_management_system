#ifndef Link_List_h
#define Link_List_h

#include <stdio.h>
#include <stdlib.h>	


/* 顺序表类型定义 */

#define	TRUE		1			//真
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功
#define UNSUCCESS	0			//失败
#define	INFEASIBLE	-1			//不可行

#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢


//数据元素的数据结构
//姓名、学号、专业、性别、年龄、联系方式、成绩。
typedef struct Student
{
	char Name[20];		//姓名
	char Num[20];		//学号
	char Major[50];		//专业
	char Gender[5];		//性别
	int Age;			//年龄
	char Tel[15];		//联系方式
	int Score;			//成绩
}LElemType;

/* 单链表结构体 */
typedef struct LNode
{
	LElemType data;
	struct LNode* next;
}LNode,*LinkList;

/* 单链表（带头结点）函数列表 */ 

//(01)初始化单链表
extern char InitList(LinkList *L);

//(02)置空单链表L，头结点保留
extern char ClearList(LinkList L);

//(03)销毁单链表L，连同头结点一起销毁
extern void DestroyList(LinkList *L);

//(04)判断单链表L是否为空
extern char ListEmpty(LinkList L);

//(05)返回单链表L元素个数
extern int ListLength(LinkList L);

//(06)在单链表L第i个位置之前插入e
extern char ListInsert(LinkList L, int i, LElemType e);

//(07)在单链表L第i个位置删除元素
extern char ListDelete(LinkList L);

//(08)用Visit函数访问单链表L。
extern char ListTraverse(LinkList L, void(*Visit)(LElemType));

extern void PrintElem(LElemType e);

#endif
