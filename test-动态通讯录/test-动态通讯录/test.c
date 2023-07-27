#include"Contact.h"
void menu()
{
	printf("********************************************\n");
	printf("**********1.add         2.del      *********\n");
	printf("**********3.serach      4.modify   *********\n");
	printf("**********5.show        6.sort     *********\n");
	printf("****************    0.exit   ***************\n");
	printf("********************************************\n");

}
int main()
{
	int input = 0;
	//创建通讯录
		//如果写成这样 ，比较麻烦，将来传参的时候会传两个
		//struct PeoInfo con[MAX]={0};//存放多少个人的信息
		//int size =0;//当前有多少个元素
	struct Contact con;//con 就是通讯录，它里面既有MAX个人的信息，也有记录当前有多少个元素的size
	Init_Contact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch(input)
		{
		case Add:
			Add_Contact(&con);//增加通讯录
			break;
		case Del:
			Del_Contact(&con);// 删除
			break;
		case Serach:
			Serach_Contact(&con);//查找联系人
			break;
		case Modify:
			Modify_Contact(&con);//修改联系人
			break;
		case Show:
			Show_Contact(&con);//展示
			break;
		case Sort:
			break;
		case Exit:
			printf("退出通讯录\n");
			break;
		default:
			destroy(&con);
			printf("选择错误!\n");
			break;
		}
	}while(input);
	return 0;
}