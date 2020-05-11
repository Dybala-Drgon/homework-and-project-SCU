#include<iostream>
#include<cstdio>
#include<cstring>
#include"staff.h"//引入staff信息
//#include<Windows.h>
using namespace std;
//界面类
class interface {
public:
	void menu();
	void display();

};
void interface ::menu() {
	cout << " | ***********欢迎进入高校工资管理系统*********|" << endl;
	cout << " | *********  (键入对应编号进入相应模块)  *****|" << endl;
	cout << " | 1——录入职员信息        2——显示职员信息  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 3——查找或修改职员信息  4——删除职员信息  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 5——保存职员信息        5——读取职员信息  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 按0退出                                     |  " << endl;
	cout << " | ------------------------------------------  |" << endl;
}	//实现菜单栏

void interface ::display() {
	int n,key=0,lab=0;
	for (;;) {
		if (lab == 0) {
			system("cls");	  //清屏
			interface::menu();		//重新打印菜单
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
			cout << "输入有误，重新输入" << endl;
			lab++;
			break;
		}
		if (key != 0)
			break;//按0退出
	}
}
	//主函数实现
int main() {
	interface service;//定义一个interface的接口
	service.display();//实现函数
	
	return 0;
}