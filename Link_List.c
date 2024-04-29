#include "Link_List.h"

char InitList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));//向内存申请地址，若申请成功，则返回起始地址给*L
	if(!(*L))								//申请地址失败
		exit(OVERFLOW);
	(*L)->next = NULL;					//将头结点的指针域置空
	
	return OK;
}

void DestroyList(LinkList *L)			//销毁所有结点 
{
	LinkList p ;
	p = *L;

	while(p)
	{
		p = (*L)->next;				//顺藤摸瓜，p为下一个结点的地址，最后一个结点的指针域为空
		free(*L);					//释放掉头结点的地址
		(*L) = p;					//删除最后一个结点时，将指针置空
	}
}

char ClearList(LinkList L)			//保留头结点 
{	
	LinkList pre, p;
	
	if(!L)						//L是空链表
	{
		return ERROR;
	}
	
	pre = L->next;				//pre是头结点的指针域，首元结点的地址

	while(pre)					//头结点指针域不为空
	{
		p = pre->next;			//将该结点的下一个结点的地址赋给p
		free(pre);				//释放该结点的地址
		pre = p;				//将下一个结点的地址赋给pre
	}

	L->next = NULL;				//将L的头结点的指针域置空，变成空链表

	return OK; 
}

char ListEmpty(LinkList L)
{
	if(L!=NULL && L->next==NULL)		//链表存在且只有头结点 
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int ListLength(LinkList L)
{
	LinkList p;
	int i;
	
	if(L)						//L存在
	{
		i = 0;
		p = L->next;			//头结点的指针域
		while(p)				//L不是空链表
		{
			i++;
			p = p->next;		//下一个结点的地址，最后一个结点指针域为空，结束循环
		}		
	}
	
	return i;					//链表长度
}

char ListInsert(LinkList L, int i, LElemType e)
{
	LinkList p, s;

	int j=0;
	p = L; 

	while(p && j<i-1)					//寻找第i-1个结点 
	{
		p = p->next;					//下一个结点的地址
		++j;
	}

	if(!p || j>i-1)						//插入位置不合理
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode));//向内存申请地址
	if(!s)								//分配地址失败
	{
		exit(OVERFLOW);
	}

	s->data = e;						//将插入的数据保存在s的数据域中
	s->next = p->next;					//将原来第i个结点的地址赋给s的指针域
	p->next = s;						//s的地址赋给p的指针域

	return OK;
}

char ListDelete(LinkList L)
{
	LinkList pre, p; 
	int i, j;
	LElemType e;

	pre = L;
	j = 0; 
	printf("请输入删除的学生位置：");
	scanf("%d", &i);

	while(pre->next && j<i-1)			//寻找第i-1个结点
	{
		pre = pre->next;
		++j;
	}
	
	if(!pre->next || j>i)			//删除位置不合理
	{
		return ERROR;
	}
	p = pre->next;					//将第i-1个结点的指针域的内容赋给p,即p为指定删除位置的结点的地址
	pre->next = p->next;			//将p的指针域里面的地址赋给第i-1个结点的指针域
	e = p->data;					//将删除的结点的数据域里面的数据赋给*e
	free(p);						//释放p的地址
	printf("删除成功！");

	return OK; 
}

char ListTraverse(LinkList L, void(*Visit)(LElemType))
{
	LinkList p;

	if(!L)					//L不存在
	{
		return ERROR;
	}
	else
	{
		p = L->next;		//p为L的头结点的指针域里面的内容，即首元结点的地址
	}

	while(p)				//L不是空链表
	{
		Visit(p->data);		//输出该结点的数据域上的数据
		p = p->next;		//下一个结点的地址，最后一个结点的指针域为空，结束循环
	}

	return OK;
}

void PrintElem(LElemType e)
{
	printf("%s ", e.Name);
	printf("%s ", e.Num);
	printf("%s ", e.Major);
	printf("%s ", e.Gender);
	printf("%d ", e.Age);
	printf("%s ", e.Tel);
	printf("%d ", e.Score);
	printf("\n");
}

