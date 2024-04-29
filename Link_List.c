#include "Link_List.h"

char InitList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));//���ڴ������ַ��������ɹ����򷵻���ʼ��ַ��*L
	if(!(*L))								//�����ַʧ��
		exit(OVERFLOW);
	(*L)->next = NULL;					//��ͷ����ָ�����ÿ�
	
	return OK;
}

void DestroyList(LinkList *L)			//�������н�� 
{
	LinkList p ;
	p = *L;

	while(p)
	{
		p = (*L)->next;				//˳�����ϣ�pΪ��һ�����ĵ�ַ�����һ������ָ����Ϊ��
		free(*L);					//�ͷŵ�ͷ���ĵ�ַ
		(*L) = p;					//ɾ�����һ�����ʱ����ָ���ÿ�
	}
}

char ClearList(LinkList L)			//����ͷ��� 
{	
	LinkList pre, p;
	
	if(!L)						//L�ǿ�����
	{
		return ERROR;
	}
	
	pre = L->next;				//pre��ͷ����ָ������Ԫ���ĵ�ַ

	while(pre)					//ͷ���ָ����Ϊ��
	{
		p = pre->next;			//���ý�����һ�����ĵ�ַ����p
		free(pre);				//�ͷŸý��ĵ�ַ
		pre = p;				//����һ�����ĵ�ַ����pre
	}

	L->next = NULL;				//��L��ͷ����ָ�����ÿգ���ɿ�����

	return OK; 
}

char ListEmpty(LinkList L)
{
	if(L!=NULL && L->next==NULL)		//���������ֻ��ͷ��� 
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
	
	if(L)						//L����
	{
		i = 0;
		p = L->next;			//ͷ����ָ����
		while(p)				//L���ǿ�����
		{
			i++;
			p = p->next;		//��һ�����ĵ�ַ�����һ�����ָ����Ϊ�գ�����ѭ��
		}		
	}
	
	return i;					//������
}

char ListInsert(LinkList L, int i, LElemType e)
{
	LinkList p, s;

	int j=0;
	p = L; 

	while(p && j<i-1)					//Ѱ�ҵ�i-1����� 
	{
		p = p->next;					//��һ�����ĵ�ַ
		++j;
	}

	if(!p || j>i-1)						//����λ�ò�����
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode));//���ڴ������ַ
	if(!s)								//�����ַʧ��
	{
		exit(OVERFLOW);
	}

	s->data = e;						//����������ݱ�����s����������
	s->next = p->next;					//��ԭ����i�����ĵ�ַ����s��ָ����
	p->next = s;						//s�ĵ�ַ����p��ָ����

	return OK;
}

char ListDelete(LinkList L)
{
	LinkList pre, p; 
	int i, j;
	LElemType e;

	pre = L;
	j = 0; 
	printf("������ɾ����ѧ��λ�ã�");
	scanf("%d", &i);

	while(pre->next && j<i-1)			//Ѱ�ҵ�i-1�����
	{
		pre = pre->next;
		++j;
	}
	
	if(!pre->next || j>i)			//ɾ��λ�ò�����
	{
		return ERROR;
	}
	p = pre->next;					//����i-1������ָ��������ݸ���p,��pΪָ��ɾ��λ�õĽ��ĵ�ַ
	pre->next = p->next;			//��p��ָ��������ĵ�ַ������i-1������ָ����
	e = p->data;					//��ɾ���Ľ�����������������ݸ���*e
	free(p);						//�ͷ�p�ĵ�ַ
	printf("ɾ���ɹ���");

	return OK; 
}

char ListTraverse(LinkList L, void(*Visit)(LElemType))
{
	LinkList p;

	if(!L)					//L������
	{
		return ERROR;
	}
	else
	{
		p = L->next;		//pΪL��ͷ����ָ������������ݣ�����Ԫ���ĵ�ַ
	}

	while(p)				//L���ǿ�����
	{
		Visit(p->data);		//����ý����������ϵ�����
		p = p->next;		//��һ�����ĵ�ַ�����һ������ָ����Ϊ�գ�����ѭ��
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

