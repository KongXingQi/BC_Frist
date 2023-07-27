#define _CRT_SECURE_NO_WARNINGS
// 头文件
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// 定义
//#define MAX 10
#define NAME_max 20
#define SEX_max 5
#define PHONE_max 12
#define ADD_max 20
#define CAPACITY_max 3
enum Choose
{
	Exit,
	Add,//增加
	Del,//删除
	Serach,//查找
	Modify,//修改
	Show,//展示
	Sort//排序

};
//每个人的类型
struct PeoInfo
{
	char name[NAME_max];//姓名
	int age;//年龄
	char sex[SEX_max];//性别
	char phone[PHONE_max];//电话
	char addr[ADD_max];//住址
};
//通讯录类型
struct Contact
{
	struct PeoInfo *data;//MAX个人的信息
	int size;//记录当前通讯录已有多少个元素个数
	int capacity;//容量
};

//声明函数
void Init_Contact(struct Contact* ps);//初始化通讯录
void Add_Contact(struct Contact* ps);//增加通讯录
void Show_Contact(const struct Contact* ps);//增加通讯录
void Del_Contact(struct Contact* ps);// 删除
void Serach_Contact(const struct Contact* ps);//查找联系人
void Modify_Contact(struct Contact* ps);//修改联系人
void destroy(struct Contact* ps);//销毁动态内存所开辟的空间


