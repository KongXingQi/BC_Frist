#include"Contact.h"


void Init_Contact(struct Contact* ps)//��ʼ��ͨѶ¼
{
	ps->data = (struct PeoInfo*)malloc(CAPACITY_max* sizeof(struct PeoInfo));//3��PeoInfo�Ĵ�С��������
	if (ps->data==NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = CAPACITY_max;
}
void chesk(struct Contact* ps)//�ж������Ƿ�����
{
	if (ps->size == ps->capacity)
	{
		//1. ���˵Ļ���������
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (CAPACITY_max + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
	}

}
void Add_Contact(struct Contact* ps)//����ͨѶ¼
{
	chesk(ps);//�ж������Ƿ�����
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰:>");
	scanf("%s", ps->data[ps->size].phone);
	printf("������סַ:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("���ӳɹ�\n");
	/*system("cls");
	if(ps->size==MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s",ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d",&(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s",ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s",ps->data[ps->size].phone);
		printf("������סַ:>");
		scanf("%s",ps->data[ps->size].addr);
		ps->size++;
		printf("���ӳɹ�\n");
	}*/
	
}
void Show_Contact(const struct Contact* ps)//չʾͨѶ¼
{
	int i= 0;
	system("cls");
	printf("%-5s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
	for(i=0;i<ps->size;i++)
	{
		printf("%-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->data[i].name,
											  ps->data[i].age,
											  ps->data[i].sex,
											  ps->data[i].phone,
											  ps->data[i].addr);
	}

}


//����ȫ����ϵ�˵ĺ���
static int Find_name(const struct Contact* ps,char name[NAME_max])// static ��¶����ȥֻ�����Contact.�г���
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
void Del_Contact(struct Contact* ps)// ɾ��
{

	int pos =0;
	char name[NAME_max];
	system("cls");
	//1.���ҷ�װһ������ ����ҵ��������Ԫ�ص��±꣬�Ҳ�������-1	
	printf("��������Ҫɾ������:>");
	scanf("%s",name);
	pos = Find_name(ps,name);
	//2. �ж��Ƿ����ҵ�
	if(pos==-1)
	{
		printf("�Ҳ�����Ҫɾ������\n");
	}
	//3. ɾ�� �����������ȫ���ƶ���ǰ�棬����������--��
	else
	{
		int j=0;
		for(j=pos;j< ps->size-1;j++)
		{
			ps->data[j]=ps->data[j+1];
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
	
}


void Serach_Contact(const struct Contact* ps)//������ϵ��
{
	char name[NAME_max];
	int pos= 0;
	system("cls");
	printf("������Ҫ���ҵ�����:>");
	scanf("%s",name);
	//1.���ҷ�װһ������ ����ҵ��������Ԫ�ص��±꣬�Ҳ�������-1	
	pos = Find_name(ps,name);
	if(pos == -1)
	{
		printf("�Ҳ�����Ҫ���ҵ���\n");
	}
	else
	{
		//2.��ӡ����
		printf("%-5s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
		printf("%-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->data[pos].name,
											  ps->data[pos].age,
											  ps->data[pos].sex,
											  ps->data[pos].phone,
											  ps->data[pos].addr);
	}
	
}
void Modify_Contact(struct Contact* ps)//�޸���ϵ��
{
	char name[NAME_max];
	int pos = 0;
	system("cls");
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s",name);
	pos=Find_name(ps,name);
	if(pos == -1)
	{
		printf("�Ҳ���Ҫ�޸��˵�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s",ps->data[pos].name);
		printf("����������:>");
		scanf("%d",&(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s",ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s",ps->data[pos].phone);
		printf("������סַ:>");
		scanf("%s",ps->data[pos].addr);
		printf("�޸ĳɹ���\n");
	}
}
void destroy(struct Contact* ps)//���ٶ�̬�ڴ������ٵĿռ�
{
	free(ps->data);
	ps->data = NULL;
}