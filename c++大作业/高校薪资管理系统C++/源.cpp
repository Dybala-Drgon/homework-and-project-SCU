#include<iostream>
#include<cstdio>
#include<cstring>
#include"staff.h"//����staff��Ϣ
//#include<Windows.h>
using namespace std;
//������
class interface {
public:
	void menu();
	void display();

};
void interface ::menu() {
	cout << " | ***********��ӭ�����У���ʹ���ϵͳ*********|" << endl;
	cout << " | *********  (�����Ӧ��Ž�����Ӧģ��)  *****|" << endl;
	cout << " | 1����¼��ְԱ��Ϣ        2������ʾְԱ��Ϣ  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 3�������һ��޸�ְԱ��Ϣ  4����ɾ��ְԱ��Ϣ  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 5��������ְԱ��Ϣ        5������ȡְԱ��Ϣ  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | ��0�˳�                                     |  " << endl;
	cout << " | ------------------------------------------  |" << endl;
}	//ʵ�ֲ˵���

void interface ::display() {
	int n,key=0,lab=0;
	for (;;) {
		if (lab == 0) {
			system("cls");	  //����
			interface::menu();		//���´�ӡ�˵�
		}
		cin >> n;
		getchar();
		switch (n)
		{
		case 1:
			lab = 0;
			break;
		case 2:
			lab = 0;
			break;
		case 3:
			lab = 0;
			break;
		case 4:
			lab = 0;
			break;
		case 5:
			lab = 0;
			break;
		case 0:
			key++;
			lab = 0;
			break;
		default:
			cout << "����������������" << endl;
			lab++;
			break;
		}
		if (key != 0)
			break;//��0�˳�
	}
}
	//������ʵ��
int main() {
	interface service;//����һ��interface�Ľӿ�
	service.display();//ʵ�ֺ���
	
	return 0;
}