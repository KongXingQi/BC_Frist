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
	//����ͨѶ¼
		//���д������ ���Ƚ��鷳���������ε�ʱ��ᴫ����
		//struct PeoInfo con[MAX]={0};//��Ŷ��ٸ��˵���Ϣ
		//int size =0;//��ǰ�ж��ٸ�Ԫ��
	struct Contact con;//con ����ͨѶ¼�����������MAX���˵���Ϣ��Ҳ�м�¼��ǰ�ж��ٸ�Ԫ�ص�size
	Init_Contact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch(input)
		{
		case Add:
			Add_Contact(&con);//����ͨѶ¼
			break;
		case Del:
			Del_Contact(&con);// ɾ��
			break;
		case Serach:
			Serach_Contact(&con);//������ϵ��
			break;
		case Modify:
			Modify_Contact(&con);//�޸���ϵ��
			break;
		case Show:
			Show_Contact(&con);//չʾ
			break;
		case Sort:
			break;
		case Exit:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			destroy(&con);
			printf("ѡ�����!\n");
			break;
		}
	}while(input);
	return 0;
}