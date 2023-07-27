#include"Contact.h"


void Init_Contact(struct Contact* ps)//初始化通讯录
{
	ps->data = (struct PeoInfo*)malloc(CAPACITY_max* sizeof(struct PeoInfo));//3个PeoInfo的大小，三个人
	if (ps->data==NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = CAPACITY_max;
}
void chesk(struct Contact* ps)//判断容量是否满了
{
	if (ps->size == ps->capacity)
	{
		//1. 满了的话增加容量
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (CAPACITY_max + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
	}

}
void Add_Contact(struct Contact* ps)//增加通讯录
{
	chesk(ps);//判断容量是否满了
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].phone);
	printf("请输入住址:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("增加成功\n");
	/*system("cls");
	if(ps->size==MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s",ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d",&(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[ps->size].phone);
		printf("请输入住址:>");
		scanf("%s",ps->data[ps->size].addr);
		ps->size++;
		printf("增加成功\n");
	}*/
	
}
void Show_Contact(const struct Contact* ps)//展示通讯录
{
	int i= 0;
	system("cls");
	printf("%-5s\t%-4s\t%-5s\t%-12s\t%-20s\n","姓名","年龄","性别","电话","地址");
	for(i=0;i<ps->size;i++)
	{
		printf("%-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->data[i].name,
											  ps->data[i].age,
											  ps->data[i].sex,
											  ps->data[i].phone,
											  ps->data[i].addr);
	}

}


//遍历全部联系人的函数
static int Find_name(const struct Contact* ps,char name[NAME_max])// static 暴露不出去只在这个Contact.中出现
{
	int i=0;
	for(i=0;i<ps->size;i++)
	{
		if(0 == strcmp(ps->data[i].name,name))
		{
			return i;
		}
	}
	return -1;
}
void Del_Contact(struct Contact* ps)// 删除
{

	int pos =0;
	char name[NAME_max];
	system("cls");
	//1.查找封装一个函数 如果找到返回这个元素的下标，找不到返回-1	
	printf("请输入需要删除的人:>");
	scanf("%s",name);
	pos = Find_name(ps,name);
	//2. 判断是否能找到
	if(pos==-1)
	{
		printf("找不到需要删除的人\n");
	}
	//3. 删除 ，把他后面的全部移动到前面，最后把总人数--；
	else
	{
		int j=0;
		for(j=pos;j< ps->size-1;j++)
		{
			ps->data[j]=ps->data[j+1];
		}
		ps->size--;
		printf("删除成功！\n");
	}
	
}


void Serach_Contact(const struct Contact* ps)//查找联系人
{
	char name[NAME_max];
	int pos= 0;
	system("cls");
	printf("请输入要查找的名字:>");
	scanf("%s",name);
	//1.查找封装一个函数 如果找到返回这个元素的下标，找不到返回-1	
	pos = Find_name(ps,name);
	if(pos == -1)
	{
		printf("找不到需要查找的人\n");
	}
	else
	{
		//2.打印出来
		printf("%-5s\t%-4s\t%-5s\t%-12s\t%-20s\n","姓名","年龄","性别","电话","地址");
		printf("%-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->data[pos].name,
											  ps->data[pos].age,
											  ps->data[pos].sex,
											  ps->data[pos].phone,
											  ps->data[pos].addr);
	}
	
}
void Modify_Contact(struct Contact* ps)//修改联系人
{
	char name[NAME_max];
	int pos = 0;
	system("cls");
	printf("请输入要修改人的名字:>");
	scanf("%s",name);
	pos=Find_name(ps,name);
	if(pos == -1)
	{
		printf("找不到要修改人的名字\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s",ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d",&(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[pos].phone);
		printf("请输入住址:>");
		scanf("%s",ps->data[pos].addr);
		printf("修改成功！\n");
	}
}
void destroy(struct Contact* ps)//销毁动态内存所开辟的空间
{
	free(ps->data);
	ps->data = NULL;
}