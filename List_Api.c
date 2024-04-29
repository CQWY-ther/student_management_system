#include "List_Api.h"
#include<string.h>

#pragma warning(disable:4996)  //#pragma warning(disable: n)��ĳ��������ΪʧЧ

void List_Init(LinkList *Student)
{
	InitList(Student);
}
//����ʾϵͳѧ������	
void Print_Length(LinkList Student)
{
	printf("�����������Ԫ�ظ��� = %d\r\n" , ListLength(Student));
}

char Insert_Element(LinkList *Student)
{
    LElemType New_Student ;
	LinkList q;
    int Locate, i;

	q = (*Student)->next;
	while(1)
	{
		printf("������ѧ�����ݲ����λ��:");
		scanf("%d", &Locate);

		if(Locate < 1 || Locate > ListLength(*Student))
		{
			printf("����λ�ò��Ϸ���\n");
		}
		else
		{
			printf("����λ�÷���Ҫ��\n");
			break;
		}
	}

    //����ѧ����Ϣ
    printf("������ѧ��������:");
    scanf("%s", &(New_Student.Name));
    printf("\n");

	printf("������ѧ����ѧ��:");
    scanf("%s", &(New_Student.Num));
    printf("\n");
    
    printf("������ѧ����רҵ:");
    scanf("%s", &(New_Student.Major));
    printf("\n");

	printf("������ѧ�����Ա�:");
    scanf("%s", &(New_Student.Gender));
    printf("\n");

    printf("������ѧ��������:");
    scanf("%d", &(New_Student.Age));
    printf("\n");

    printf("������ѧ������ϵ��ʽ:");
    scanf("%s", &(New_Student.Tel));
    printf("\n");

    printf("������ѧ���ĳɼ�:");
    scanf("%d", &(New_Student.Score));
    printf("\n");
    
	while(q)
	{
		if(strcmp(q->data.Num, New_Student.Num))
			q = q->next;
		else
		{
			printf("����ѧ���ظ������������룡");
			return ERROR;
		}
	}
	for(i=0;i<strlen(New_Student.Name);i++)
	{
		if((0<=(New_Student.Name)[i]) && ((New_Student.Name)[i]<=127))
		{
			printf("�������ִ������������룡");
			return ERROR;
		}
	}

	if(strcmp(New_Student.Gender, "��") && strcmp(New_Student.Gender, "Ů"))
	{
		printf("�����Ա�������������룡");
		return ERROR;
	}

	if((New_Student.Age>100) || (New_Student.Age<0))
	{
		printf("��������������������룡");
		return ERROR;
	}
	
	ListInsert(*Student, Locate, New_Student);
}

void Insert_AllElement(LinkList *Student)
{
	const LElemType student[6] = {
								{"С��", "202201", "��Ϣ������ѧ", "��", 20, "12312312310", 98}, 
								{"С��", "202202", "��Ϣ������ѧ", "��", 21, "12312312311", 94}, 
								{"С��", "202203", "��Ϣ������ѧ", "Ů", 22, "12312312312", 97}, 
								{"С��", "202204", "��Ϣ������ѧ", "��", 19, "12312312313", 95}, 
								{"С��", "202205", "��Ϣ������ѧ", "Ů", 18, "12312312314", 98}, 
								{"С��", "202206", "��Ϣ������ѧ", "��", 20, "12312312315", 94}
							};
	int i;

	//����ѧ��������Ϣ
	for(i=0;i<6;i++)
	{
		ListInsert(*Student,i+1,student[i]);
	}
}

//����ѧ���޸�ѧ����Ϣ
char NumChangeInfo(LinkList L)
{
	LinkList p, q;
	LElemType s;
	int i, count;
	char num[20];
	printf("�������޸�ѧ����ѧ�ţ�");
	scanf("%s", &num);
	count =0;
	p = L->next;
	q = L->next;

	while(L->next)
	{
		count++; //������
		L = L->next;
	}
	for(i=0;i<count;i++)
	{
		if(!strcmp(p->data.Num, num))
		{
			printf("�޸���Ϣǰ��ѧ������Ϣ��\n");
			PrintElem(p->data);
			printf("�����뱻�޸ĵ�ѧ�Ŷ�Ӧѧ������Ϣ��\n");
			//����ѧ����Ϣ
			printf("������ѧ��������:");
			scanf("%s", &(s.Name));
			printf("\n");

			printf("������ѧ����ѧ��:");
			scanf("%s", &(s.Num));
			printf("\n");
    
			printf("������ѧ����רҵ:");
			scanf("%s", &(s.Major));
			printf("\n");

			printf("������ѧ�����Ա�:");
			scanf("%s", &(s.Gender));
			printf("\n");

			printf("������ѧ��������:");
			scanf("%d", &(s.Age));
			printf("\n");

			printf("������ѧ������ϵ��ʽ:");
			scanf("%s", &(s.Tel));
			printf("\n");

			printf("������ѧ���ĳɼ�:");
			scanf("%d", &(s.Score));
			printf("\n");
			while(q)
			{
				if(strcmp(q->data.Num, s.Num) ||(!strcmp(s.Num, p->data.Num)))
					q = q->next;
				else
				{
					printf("����ѧ���ظ������������룡");
					return ERROR;
				}
			}
			for(i=0;i<strlen(s.Name);i++)
			{
				if((0<=(s.Name)[i]) && ((s.Name)[i]<=127))
				{
					printf("�������ִ������������룡");
					return ERROR;
				}
			}
			if(strcmp(s.Gender, "��") && strcmp(s.Gender, "Ů"))
			{
				printf("�����Ա�������������룡");
				return ERROR;
			}
			if((s.Age>100) || (s.Age<0))
			{
				printf("��������������������룡");
				return ERROR;
			}
			p->data = s;
			return OK;
		}
		p = p->next ;
	}
	printf("��ѧ��������\n");
	return ERROR;
}

// ����ѧ�š���������Ԫ��
char Print_NameElem(LinkList L)
{
	LinkList p;
	LElemType e;
	int i=0;
	printf("�������ѯѧ����������");
	scanf("%s", &(e.Name));
	

	if(L)								//L����
	{
		p = L->next;					//pΪͷ����ָ����
		
		while(p)						//L��Ϊ������
		{
			if(strcmp(e.Name, p->data.Name))	//�������������
			{
				p = p->next;
				if((p==NULL) && i==0)				//ʧ��ʱ�Ѿ������һ����� 
				{
					printf("û��Ϊ��������ѧ���� ���������룡");
					return ERROR;
				}
			}
			else						//�ҵ�����������Ԫ��
			{
				PrintElem(p->data);
				i++;
				p = p->next;
			}
		}
		printf("����Ϊ%s��ѧ������%d��", e.Name, i);
	}	
}

char Print_NumElem(LinkList L)
{
	LinkList p;
	LElemType e;
	printf("�������ѯѧ����ѧ�ţ�");
	scanf("%s", &(e.Num));

	if(L)								//L����
	{
		p = L->next;					//pΪͷ����ָ����
		
		while(p)						//L��Ϊ������
		{
			if(strcmp(e.Num, p->data.Num))	//�������������
			{
				p = p->next;
				if(p==NULL)				//ʧ��ʱ�Ѿ������һ����� 
				{
					printf("û��Ϊ��ѧ�ŵ�ѧ���� ���������룡");
					return ERROR;
				}
			}
			else						//�ҵ�����������Ԫ��
			{
				PrintElem(p->data);
				break;
			}
		}	
	}	
}

char ScoreSort(LinkList L)
{
	LinkList p, q, s;
	int i, count, num;
	p = L;
	count=0;

	while(p->next)
	{
		count++; //������
		p=p->next;
	}
	for(i=0;i<count-1;i++)
	{
		num = count-i-1;
		q = L->next;
		p = q->next;
		s = L;
		while(num--)
		{
			if(q->data.Score > p->data.Score)
			{
				q->next = p->next;
				p->next = q;
				s->next = p;
			}
			s = s->next;
			q = s->next;
			p = q->next;
		}
	}
	printf("�������\n");
	return OK;
}

void Menu(void)
{
	unsigned int ID;
	LinkList Student;

    //��ʼ��˳���
	List_Init(&Student);

	//��������
	Insert_AllElement(&Student);

	while(1)
	{
		printf("\n\t\t\t++++++++++++++++++++++++++++++++++++++++\n\t\t\t\t+  ѡ������Ŀ���  +\n\t\t\t++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n		*************************�˵���************************\n");
		printf("\t\t\t*����ʾϵͳѧ������			  *\n");
		printf("\t\t\t*����ʾ���е�ѧ����Ϣ����		  *\n");
		printf("\t\t\t*��ָ��λ�ò���ѧ������Ϣ����   *\n");
		printf("\t\t\t*�ܸ���ѧ���޸�ѧ������Ϣ����	  *\n");
		printf("\t\t\t*��ɾ��ָ��λ��ѧ������Ϣ����	  *\n");
		printf("\t\t\t*�޸�����������ѧ������Ϣ����   *\n");
		printf("\t\t\t*�߸���ѧ�Ų���ѧ������Ϣ����   *\n");
		printf("\t\t\t*��ɼ���������			      *\n");
		printf("\t\t\t*���˳�ϵͳ					  *\n");
		printf("		*******************************************************\n");
	
		//���빦�ܱ��	
		printf("\t\t\t������ѡ�[\t]\b\b\b");
		scanf("%d",&ID);
	
		switch(ID)
		{
			case 1:
				Print_Length(Student);
				break;

			case 2:
				ListTraverse( Student , *PrintElem);
				break;

			case 3:
				Insert_Element(&Student);
				break;

			case 4:
				NumChangeInfo(Student);
				break;

			case 5:
				ListDelete(Student);
				break;

			case 6:
				Print_NameElem(Student);
				break;

			case 7:
				Print_NumElem(Student);
				break;

			case 8:
				ScoreSort(Student);
				ListTraverse( Student , *PrintElem);
				break;

			case 9:
				exit(0);
				break;

			default:
				printf("\t\t����ѡ���������������ѡ��\n");
				break;
		}
	}
}
