#ifndef Link_List_h
#define Link_List_h

#include <stdio.h>
#include <stdlib.h>	


/* ˳������Ͷ��� */

#define	TRUE		1			//��
#define	FALSE		0			//��
#define YES			1			//��
#define NO          0			//��
#define	OK			1			//ͨ��
#define	ERROR		0			//����
#define SUCCESS		1			//�ɹ�
#define UNSUCCESS	0			//ʧ��
#define	INFEASIBLE	-1			//������

#define	OVERFLOW	-2			//��ջ����
#define UNDERFLOW	-3			//��ջ����


//����Ԫ�ص����ݽṹ
//������ѧ�š�רҵ���Ա����䡢��ϵ��ʽ���ɼ���
typedef struct Student
{
	char Name[20];		//����
	char Num[20];		//ѧ��
	char Major[50];		//רҵ
	char Gender[5];		//�Ա�
	int Age;			//����
	char Tel[15];		//��ϵ��ʽ
	int Score;			//�ɼ�
}LElemType;

/* ������ṹ�� */
typedef struct LNode
{
	LElemType data;
	struct LNode* next;
}LNode,*LinkList;

/* ��������ͷ��㣩�����б� */ 

//(01)��ʼ��������
extern char InitList(LinkList *L);

//(02)�ÿյ�����L��ͷ��㱣��
extern char ClearList(LinkList L);

//(03)���ٵ�����L����ͬͷ���һ������
extern void DestroyList(LinkList *L);

//(04)�жϵ�����L�Ƿ�Ϊ��
extern char ListEmpty(LinkList L);

//(05)���ص�����LԪ�ظ���
extern int ListLength(LinkList L);

//(06)�ڵ�����L��i��λ��֮ǰ����e
extern char ListInsert(LinkList L, int i, LElemType e);

//(07)�ڵ�����L��i��λ��ɾ��Ԫ��
extern char ListDelete(LinkList L);

//(08)��Visit�������ʵ�����L��
extern char ListTraverse(LinkList L, void(*Visit)(LElemType));

extern void PrintElem(LElemType e);

#endif
