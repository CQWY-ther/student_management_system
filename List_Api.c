#include "List_Api.h"
#include<string.h>

#pragma warning(disable:4996)  //#pragma warning(disable: n)将某个警报置为失效

void List_Init(LinkList *Student)
{
	InitList(Student);
}
//②显示系统学生人数	
void Print_Length(LinkList Student)
{
	printf("单链表的数据元素个数 = %d\r\n" , ListLength(Student));
}

char Insert_Element(LinkList *Student)
{
    LElemType New_Student ;
	LinkList q;
    int Locate, i;

	q = (*Student)->next;
	while(1)
	{
		printf("请输入学生数据插入的位置:");
		scanf("%d", &Locate);

		if(Locate < 1 || Locate > ListLength(*Student))
		{
			printf("输入位置不合法。\n");
		}
		else
		{
			printf("输入位置符合要求。\n");
			break;
		}
	}

    //输入学生信息
    printf("请输入学生的姓名:");
    scanf("%s", &(New_Student.Name));
    printf("\n");

	printf("请输入学生的学号:");
    scanf("%s", &(New_Student.Num));
    printf("\n");
    
    printf("请输入学生的专业:");
    scanf("%s", &(New_Student.Major));
    printf("\n");

	printf("请输入学生的性别:");
    scanf("%s", &(New_Student.Gender));
    printf("\n");

    printf("请输入学生的年龄:");
    scanf("%d", &(New_Student.Age));
    printf("\n");

    printf("请输入学生的联系方式:");
    scanf("%s", &(New_Student.Tel));
    printf("\n");

    printf("请输入学生的成绩:");
    scanf("%d", &(New_Student.Score));
    printf("\n");
    
	while(q)
	{
		if(strcmp(q->data.Num, New_Student.Num))
			q = q->next;
		else
		{
			printf("输入学号重复，请重新输入！");
			return ERROR;
		}
	}
	for(i=0;i<strlen(New_Student.Name);i++)
	{
		if((0<=(New_Student.Name)[i]) && ((New_Student.Name)[i]<=127))
		{
			printf("输入名字错误，请重新输入！");
			return ERROR;
		}
	}

	if(strcmp(New_Student.Gender, "男") && strcmp(New_Student.Gender, "女"))
	{
		printf("输入性别错误，请重新输入！");
		return ERROR;
	}

	if((New_Student.Age>100) || (New_Student.Age<0))
	{
		printf("输入年龄错误，请重新输入！");
		return ERROR;
	}
	
	ListInsert(*Student, Locate, New_Student);
}

void Insert_AllElement(LinkList *Student)
{
	const LElemType student[6] = {
								{"小张", "202201", "信息与计算科学", "男", 20, "12312312310", 98}, 
								{"小王", "202202", "信息与计算科学", "男", 21, "12312312311", 94}, 
								{"小李", "202203", "信息与计算科学", "女", 22, "12312312312", 97}, 
								{"小刘", "202204", "信息与计算科学", "男", 19, "12312312313", 95}, 
								{"小孙", "202205", "信息与计算科学", "女", 18, "12312312314", 98}, 
								{"小吴", "202206", "信息与计算科学", "男", 20, "12312312315", 94}
							};
	int i;

	//插入学生数据信息
	for(i=0;i<6;i++)
	{
		ListInsert(*Student,i+1,student[i]);
	}
}

//根据学号修改学生信息
char NumChangeInfo(LinkList L)
{
	LinkList p, q;
	LElemType s;
	int i, count;
	char num[20];
	printf("请输入修改学生的学号：");
	scanf("%s", &num);
	count =0;
	p = L->next;
	q = L->next;

	while(L->next)
	{
		count++; //结点个数
		L = L->next;
	}
	for(i=0;i<count;i++)
	{
		if(!strcmp(p->data.Num, num))
		{
			printf("修改信息前该学生的信息：\n");
			PrintElem(p->data);
			printf("请输入被修改的学号对应学生的信息：\n");
			//输入学生信息
			printf("请输入学生的姓名:");
			scanf("%s", &(s.Name));
			printf("\n");

			printf("请输入学生的学号:");
			scanf("%s", &(s.Num));
			printf("\n");
    
			printf("请输入学生的专业:");
			scanf("%s", &(s.Major));
			printf("\n");

			printf("请输入学生的性别:");
			scanf("%s", &(s.Gender));
			printf("\n");

			printf("请输入学生的年龄:");
			scanf("%d", &(s.Age));
			printf("\n");

			printf("请输入学生的联系方式:");
			scanf("%s", &(s.Tel));
			printf("\n");

			printf("请输入学生的成绩:");
			scanf("%d", &(s.Score));
			printf("\n");
			while(q)
			{
				if(strcmp(q->data.Num, s.Num) ||(!strcmp(s.Num, p->data.Num)))
					q = q->next;
				else
				{
					printf("输入学号重复，请重新输入！");
					return ERROR;
				}
			}
			for(i=0;i<strlen(s.Name);i++)
			{
				if((0<=(s.Name)[i]) && ((s.Name)[i]<=127))
				{
					printf("输入名字错误，请重新输入！");
					return ERROR;
				}
			}
			if(strcmp(s.Gender, "男") && strcmp(s.Gender, "女"))
			{
				printf("输入性别错误，请重新输入！");
				return ERROR;
			}
			if((s.Age>100) || (s.Age<0))
			{
				printf("输入年龄错误，请重新输入！");
				return ERROR;
			}
			p->data = s;
			return OK;
		}
		p = p->next ;
	}
	printf("该学生不存在\n");
	return ERROR;
}

// 根据学号、姓名查找元素
char Print_NameElem(LinkList L)
{
	LinkList p;
	LElemType e;
	int i=0;
	printf("请输入查询学生的姓名：");
	scanf("%s", &(e.Name));
	

	if(L)								//L存在
	{
		p = L->next;					//p为头结点的指针域
		
		while(p)						//L不为空链表
		{
			if(strcmp(e.Name, p->data.Name))	//如果不满足条件
			{
				p = p->next;
				if((p==NULL) && i==0)				//失配时已经是最后一个结点 
				{
					printf("没有为该姓名的学生， 请重新输入！");
					return ERROR;
				}
			}
			else						//找到满足条件的元素
			{
				PrintElem(p->data);
				i++;
				p = p->next;
			}
		}
		printf("名字为%s的学生共有%d人", e.Name, i);
	}	
}

char Print_NumElem(LinkList L)
{
	LinkList p;
	LElemType e;
	printf("请输入查询学生的学号：");
	scanf("%s", &(e.Num));

	if(L)								//L存在
	{
		p = L->next;					//p为头结点的指针域
		
		while(p)						//L不为空链表
		{
			if(strcmp(e.Num, p->data.Num))	//如果不满足条件
			{
				p = p->next;
				if(p==NULL)				//失配时已经是最后一个结点 
				{
					printf("没有为该学号的学生， 请重新输入！");
					return ERROR;
				}
			}
			else						//找到满足条件的元素
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
		count++; //结点个数
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
	printf("排序完成\n");
	return OK;
}

void Menu(void)
{
	unsigned int ID;
	LinkList Student;

    //初始化顺序表
	List_Init(&Student);

	//插入数据
	Insert_AllElement(&Student);

	while(1)
	{
		printf("\n\t\t\t++++++++++++++++++++++++++++++++++++++++\n\t\t\t\t+  选择功能项目编号  +\n\t\t\t++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n		*************************菜单栏************************\n");
		printf("\t\t\t*①显示系统学生人数			  *\n");
		printf("\t\t\t*②显示所有的学生信息数据		  *\n");
		printf("\t\t\t*③指定位置插入学生的信息数据   *\n");
		printf("\t\t\t*④根据学号修改学生的信息数据	  *\n");
		printf("\t\t\t*⑤删除指定位置学生的信息数据	  *\n");
		printf("\t\t\t*⑥根据姓名查找学生的信息数据   *\n");
		printf("\t\t\t*⑦根据学号查找学生的信息数据   *\n");
		printf("\t\t\t*⑧成绩升序排列			      *\n");
		printf("\t\t\t*⑨退出系统					  *\n");
		printf("		*******************************************************\n");
	
		//输入功能编号	
		printf("\t\t\t请输入选项：[\t]\b\b\b");
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
				printf("\t\t输入选项不满足需求，请重新选择\n");
				break;
		}
	}
}
