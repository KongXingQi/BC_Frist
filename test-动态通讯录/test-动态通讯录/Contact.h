#define _CRT_SECURE_NO_WARNINGS
// ͷ�ļ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// ����
//#define MAX 10
#define NAME_max 20
#define SEX_max 5
#define PHONE_max 12
#define ADD_max 20
#define CAPACITY_max 3
enum Choose
{
	Exit,
	Add,//����
	Del,//ɾ��
	Serach,//����
	Modify,//�޸�
	Show,//չʾ
	Sort//����

};
//ÿ���˵�����
struct PeoInfo
{
	char name[NAME_max];//����
	int age;//����
	char sex[SEX_max];//�Ա�
	char phone[PHONE_max];//�绰
	char addr[ADD_max];//סַ
};
//ͨѶ¼����
struct Contact
{
	struct PeoInfo *data;//MAX���˵���Ϣ
	int size;//��¼��ǰͨѶ¼���ж��ٸ�Ԫ�ظ���
	int capacity;//����
};

//��������
void Init_Contact(struct Contact* ps);//��ʼ��ͨѶ¼
void Add_Contact(struct Contact* ps);//����ͨѶ¼
void Show_Contact(const struct Contact* ps);//����ͨѶ¼
void Del_Contact(struct Contact* ps);// ɾ��
void Serach_Contact(const struct Contact* ps);//������ϵ��
void Modify_Contact(struct Contact* ps);//�޸���ϵ��
void destroy(struct Contact* ps);//���ٶ�̬�ڴ������ٵĿռ�


