#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"staff.h"//引入staff信息

using namespace std;
Teacher* teacher_head=new Teacher;
Experimenter* exper_head=new Experimenter;
Admini* admi_head=new Admini;
Teacher_Experimenter* teach_exper_head=new Teacher_Experimenter;
Admini_Teacher* admi_teach_head=new Admini_Teacher;	//作为链表头


//界面类
class interface {
public:
	void menu();
	void display();
	void choose_add();
	void choose_show();
	void showall();
	void search();
	void del();
	void save();//				 保存函数
	void read();//               读取函数
	void compare
	(char s[],int n, Teacher* &teacher_pos, Experimenter* &exper_pos, 
		Admini* &admi_pos, Teacher_Experimenter* &teach_exper_pos, Admini_Teacher* &admi_teach_pos);
	//指针的引用才能修改（查了某sdn，博客园，终于发现了问题）
	//比较函数，用于查找信息

	//增加成员提炼成函数模板，提高复用性
	template<typename Ptr>
	void add(Ptr* p,Ptr* t) {
		while (p->next != nullptr) {
			p = p->next;
		}//找到数据的末尾
		p->next = t;
		t->Setinfo();
		t->num = p->num + 1;
		cout << "录入成功" << endl;
		cout << "任意键返回" << endl;
		getchar();
	}


};
void interface ::menu() {
	cout << " | ***********欢迎进入高校工资管理系统*********|" << endl;
	cout << " | *********  (键入对应编号进入相应模块)  *****|" << endl;
	cout << " | 1——录入职员信息        2——显示职员信息  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 3——查找或修改职员信息  4——删除职员信息  |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 5——保存职员信息						    |" << endl;
	cout << " | ------------------------------------------  |" << endl;
	cout << " | 按0退出                                     |" << endl;
	cout << " | ------------------------------------------  |" << endl;
}	//实现菜单栏

void interface ::display() {
	int n,key=0,lab=0;
	for (;;) {
		if (lab == 0) {
			system("cls");		    //清屏
			interface::menu();		//重新打印菜单
		}
		cin >> n;
		getchar();
		switch (n)
		{
		case 1:	 //录入信息	 ,已测试，无问题
			choose_add();
			lab = 0;
			break;
		case 2:	//显示信息
			choose_show();
			lab = 0;
			break;
		case 3:	//查找或修改
			search();
			lab = 0;
			break;
		case 4:	  //删除
			lab = 0;
			del();
			break;
		case 5:	//  保存

			save();
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
void interface::choose_add() {
	system("cls");//清屏
	cout << "选择新增类型" << endl;
	cout << "1:任课教师     2：实验员" << endl;
	cout << "3:行政人员     4：教师兼职实验员" << endl;
	cout << "5:行政人员兼职教师  (其他任意键退出)" << endl;
	int n;
	cin >> n;
	getchar();	
	
	switch (n)
	{
	case 1:
	{	Teacher* t = new Teacher;
		add<Teacher>(teacher_head, t);
		break;
	}
	case 2:
	{
		Experimenter* t = new Experimenter;
		add<Experimenter>(exper_head, t);
		break;
	}
	case 3:
	{
		Admini* t = new Admini;
		add<Admini>(admi_head, t);
		break;
	}
	case 4: {
		Teacher_Experimenter* t = new Teacher_Experimenter;
		add<Teacher_Experimenter>(teach_exper_head, t);
		break;
	}
	case 5:
	{
		Admini_Teacher* t = new Admini_Teacher;
		add<Admini_Teacher>(admi_teach_head, t);
		break;
	}
	default:
		break;
	}

}
void interface::compare(char s[], int n, Teacher* &teacher_pos, Experimenter* &exper_pos, Admini* &admi_pos, Teacher_Experimenter* &teach_exper_pos, Admini_Teacher* &admi_teach_pos) {
	 //用于模糊查找，即不确定该id name属于哪个部门，因此遍历五个部门
	if (n == 1) {
		Teacher* temp = teacher_head;
		while (temp->next!=nullptr) {
			if (strcmp(s, temp->next->GetID()) == 0) {		//若相同，打印信息，直接结束（假设没有同名）
				showinfo(temp->next);		//调用虚函数
				teacher_pos = temp;
				return;
			}	
			temp = temp->next;
		}
		Experimenter* temp1 = exper_head;
		while (temp1->next!=nullptr) {
			if (strcmp(s, temp1->next->GetID()) == 0) {
				showinfo(temp1->next);
				exper_pos = temp1;
				return;
			}
			temp1 = temp1->next;
		}
		Admini* temp2 = admi_head;
		while (temp2->next!=nullptr) {
			temp2 = temp2->next;
			if (temp2 == nullptr)break;
			if (strcmp(s, temp2->next->GetID()) == 0) {
				showinfo(temp2->next);
				admi_pos = temp2;
				return;
			}
		}
		Teacher_Experimenter* temp3 = teach_exper_head;
		while (temp3->next != nullptr) {
			if (strcmp(s, temp3->next->GetID()) == 0) {
				showinfo(temp3->next);
				teach_exper_pos = temp3;
				return;
			}
			temp3 = temp3->next;
		}
		Admini_Teacher* temp4 = admi_teach_head;
		while (temp4->next != nullptr) {
			if (strcmp(s, temp4->next->GetID()) == 0) {
				showinfo(temp4->next);
				admi_teach_pos = temp4;
				return;
			}
			temp4 = temp4->next;
		}
		cout << "查无此人" << endl;
	}
	else if(n==2) {
			Teacher* temp = teacher_head;
			while (temp ->next!= nullptr) {
				if (strcmp(s, temp->next->GetName()) == 0) {		//若相同，打印信息，直接结束（假设没有同名）
					showinfo(temp->next);							//调用虚函数
					teacher_pos = temp;
					return;
				}
				temp = temp->next;
			}
			Experimenter* temp1 = exper_head;
			while (temp1->next != nullptr) {
				if (strcmp(s, temp1->next->GetName()) == 0) {
					showinfo(temp1->next);
					exper_pos = temp1;
					return;
				}
				temp1 = temp1->next;
			}
			Admini* temp2 = admi_head;
			while (temp2->next != nullptr) {
			
				if (strcmp(s, temp2->next->GetName()) == 0) {
					showinfo(temp2->next);
					admi_pos = temp2;
					return;
				}
				temp2 = temp2->next;
			}
			Teacher_Experimenter* temp3 = teach_exper_head;
			while (temp3->next != nullptr) {
				if (strcmp(s, temp3->next->GetName()) == 0) {
				showinfo(temp3->next);
				teach_exper_pos = temp3;
					return;
				}
				temp3 = temp3->next;
			}
			Admini_Teacher* temp4 = admi_teach_head;
			while (temp4->next != nullptr) {
				if (strcmp(s, temp4->next->GetName()) == 0) {
					showinfo(temp4->next);
					admi_teach_pos = temp4;
					return;
				}
				temp4 = temp4->next;
			}
			cout << "查无此人" << endl;
		}
	else return;
}
void interface::showall() {
	Teacher* temp = teacher_head;
	if(temp->next!=nullptr)
	temp->showmenu();
	while (temp != nullptr) {
		temp = temp->next;
		if
			(temp == nullptr)break;
		else
			temp->showall();
		
	}
	cout << endl;
	Experimenter* temp1 = exper_head;
	if (temp1->next != nullptr)
	temp1->showmenu();
	while (temp1 != nullptr) {
		temp1 = temp1->next;
		if (temp1 == nullptr)break;
		temp1->showall();
	}
	cout << endl;
	Admini* temp2 = admi_head;
	if (temp2->next != nullptr)
	temp2->showmenu();
	while (temp2 != nullptr) {
		temp2 = temp2->next;
		if (temp2 == nullptr)break;
		temp2->showall();
	}
	cout << endl;
	Teacher_Experimenter* temp3 = teach_exper_head;
	if (temp3->next != nullptr)
	temp3->showmenu();
	while (temp3 != nullptr) {
		temp3 = temp3->next;
		if (temp3 == nullptr)break;
		temp3->showall();
	}
	cout << endl;
	Admini_Teacher* temp4 = admi_teach_head;
	if (temp4->next != nullptr)
	temp4->showmenu();
	while (temp4 != nullptr) {
		temp4 = temp4->next;
		if (temp4 == nullptr)break;
		temp4->showall();
	}
	cout << endl;
	cout << "按任意键退出" << endl;
	getchar();
}

void interface::choose_show() {
	int n;
	Teacher* teacher_pos = nullptr;//定位指针，用于查找和修改
	Experimenter* exper_pos = nullptr;
	Admini* admi_pos = nullptr;
	Teacher_Experimenter* teach_exper_pos = nullptr;
	Admini_Teacher* admi_teach_pos = nullptr;

	system("cls");
	cout << "1:按id查找     2:按姓名查找	3:显示全部   (其他任意键退出)" << endl;
	cin >> n;
	getchar();
	if (n == 3) {
		showall();
		return;
	}
	cout << "输入id或姓名" << endl;
	char com[21] = { '\0' };
	cin >> com;
	getchar();//吃掉回车
	compare(com, n,teacher_pos,exper_pos,admi_pos,teach_exper_pos,admi_teach_pos);
	cout << "任意键退出" << endl;
	getchar();
}

void interface::search() {
	int n;
	Teacher* teacher_pos = nullptr;															//定位指针，用于查找和修改
	Experimenter* exper_pos = nullptr;
	Admini* admi_pos = nullptr;
	Teacher_Experimenter* teach_exper_pos = nullptr;
	Admini_Teacher* admi_teach_pos = nullptr;
	cout << "1:按id查找     2:按姓名查找"<< endl;
	cin >> n;
	getchar();
	cout << "输入id或姓名" << endl;
	char com[21] = { '\0' };
	cin >> com;
	getchar();
	compare(com, n, teacher_pos, exper_pos, admi_pos, teach_exper_pos, admi_teach_pos);		//调用比较函数查找
	cout << "开始修改" << endl;
	if (teacher_pos != nullptr) {
		teacher_pos->next->Setinfo();																		//重置单位的信息
		cout << "修改成功" << endl;
		getchar();
		return;
	}
	if (exper_pos != nullptr) {
		exper_pos->next->Setinfo();
		cout << "修改成功" << endl;
		getchar();
		return;
	}
	if (admi_pos != nullptr) {
		admi_pos->next->Setinfo();
		cout << "修改成功" << endl;
		getchar();
		return;
	}
	if (teach_exper_pos != nullptr) {
		teach_exper_pos->next->Setinfo();
		cout << "修改成功" << endl;
		getchar();
		return;
	}
	if (admi_teach_pos != nullptr) {
		admi_teach_pos->next->Setinfo();
		cout << "修改成功" << endl;
		getchar();
		return;
	}
	

}

void interface::del() {
	int n;
	Teacher* teacher_pos = nullptr;															//定位指针，用于查找和修改
	Experimenter* exper_pos = nullptr;
	Admini* admi_pos = nullptr;
	Teacher_Experimenter* teach_exper_pos = nullptr;
	Admini_Teacher* admi_teach_pos = nullptr;
	cout << "1:按id查找     2:按姓名查找" << endl;
	cin >> n;
	getchar();
	cout << "输入id或姓名" << endl;
	char com[21] = { '\0' };
	cin >> com;
	getchar();
	compare(com, n, teacher_pos, exper_pos, admi_pos, teach_exper_pos, admi_teach_pos);		//调用比较函数查找
	if (teacher_pos != nullptr) {
		Teacher* p = teacher_pos->next;
		teacher_pos->next = teacher_pos->next->next;
		delete p;//删除节点
		cout << "删除成功" << endl;
		getchar();
		return;
	}
	if (exper_pos != nullptr) {
		Experimenter* p = exper_pos->next;
		exper_pos->next = exper_pos->next->next;
		delete p;
		cout << "删除成功" << endl;
		getchar();
		return;
	}
	if (admi_pos != nullptr) {
		Admini* p = admi_pos->next;
		admi_pos->next = admi_pos->next->next;
		delete p;
		cout << "删除成功" << endl;
		getchar();
		return;
	}
	if (teach_exper_pos != nullptr) {
		Teacher_Experimenter* p = teach_exper_pos->next;
		teach_exper_pos->next = teach_exper_pos->next->next;
		delete p;
		cout << "删除成功" << endl;
		getchar();
		return;
	}
	if (admi_teach_pos != nullptr) {
		Admini_Teacher* p = admi_teach_pos->next;
		admi_teach_pos->next = admi_teach_pos->next->next;
		delete p;
		cout << "删除成功" << endl;
		getchar();
		return;
	}
}
//		保存函数
void interface::save() {
	FILE* fp1 =  fopen("D:\\data\\da1.dal", "wb");
	FILE* fp2 = fopen("D:\\data\\da2.dal", "wb");
	FILE* fp3 = fopen("D:\\data\\da3.dal", "wb");
	FILE* fp4 = fopen("D:\\data\\da4.dal", "wb");
	FILE* fp5 = fopen("D:\\data\\da5.dal", "wb");
	if (fp1 == NULL||fp2==NULL||fp3==NULL||fp4==NULL||fp5==NULL)
	{
		printf("Can not open the file!\n");
		cout << "任意键退出" << endl;
		getchar();
		return;
	}
	Teacher* teacher_pos = teacher_head->next;
	Experimenter* exper_pos = exper_head->next;
	Admini* admi_pos = admi_head->next;
	Teacher_Experimenter* teach_exper_pos = teach_exper_head->next;
	Admini_Teacher* admi_teach_pos = admi_teach_head->next;
	while (teacher_pos != NULL)
	{
		if (fwrite(teacher_pos, sizeof(class Teacher), 1, fp1) != 1)
		{
			cout << "写入teacher数据出错" << endl;
			fclose(fp1);
			return;
		}
		teacher_pos = teacher_pos->next;
	}		
	while (exper_pos != NULL)
	{
		if (fwrite(exper_pos, sizeof(class Experimenter), 1, fp2) != 1)
		{
			cout << "写入experimenter数据出错" << endl;
			fclose(fp2);
			return;
		}
		exper_pos = exper_pos->next;
	}
	while (admi_pos != NULL)
	{
		if (fwrite(admi_pos, sizeof(class Admini), 1, fp3) != 1)
		{
			cout << "写入admini数据出错" << endl;
			fclose(fp3);
			return;
		}
		admi_pos = admi_pos->next;
	}
	while (teach_exper_pos != NULL)
	{
		if (fwrite(teach_exper_pos, sizeof(class Teacher_Experimenter), 1, fp4) != 1)
		{
			cout << "写入teacher_experimenter数据出错" << endl;
			fclose(fp4);
			return;
		}
		teach_exper_pos = teach_exper_pos->next;
	}
	while (admi_teach_pos != NULL)
	{
		if (fwrite(admi_teach_pos, sizeof(class Admini_Teacher), 1, fp5) != 1)
		{
			cout << "写入admi_teach数据出错" << endl;
			fclose(fp5);
			return;
		}
		admi_teach_pos = admi_teach_pos->next;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);

	cout<<"存储完成\n"<<endl;
	cout << "任意键退出" << endl;
	getchar();
}

void interface::read() {
	FILE* fp1 = fopen("D:\\data\\da1.dal", "rb+");
	FILE* fp2 = fopen("D:\\data\\da2.dal", "rb+");
	FILE* fp3 = fopen("D:\\data\\da3.dal", "rb+");
	FILE* fp4 = fopen("D:\\data\\da4.dal", "rb+");
	FILE* fp5 = fopen("D:\\data\\da5.dal", "rb+");
	int ch;
	if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL || fp5 == NULL)
	{
		printf("Can not open the file!\n");
		cout << "任意键退出" << endl;
		getchar();
		return;
	}
	Teacher* teacher_pos = teacher_head;
	Experimenter* exper_pos = exper_head;														   
	Admini* admi_pos = admi_head;
	Teacher_Experimenter* teach_exper_pos = teach_exper_head;
	Admini_Teacher* admi_teach_pos = admi_teach_head;
	 do
	{
		 ch = fgetc(fp1);
		 if (ch == EOF)break;
		Teacher* t = new Teacher; 
		fread(t,sizeof(class Teacher), 1, fp1);
		teacher_pos->next = t;                 
		teacher_pos = teacher_pos->next;
		
	} while (teacher_pos->next != NULL);

	 do
	{	ch = fgetc(fp2);
		if (ch == EOF)break;  
		Experimenter* t = new(Experimenter);
		fread(t, sizeof(class Experimenter), 1, fp2);
		exper_pos->next = t;
		exper_pos = exper_pos->next;

	} while (exper_pos->next != NULL);
	  do
	{
		  ch = fgetc(fp3);
		  if (ch == EOF)break;
		Admini* t = new(Admini);
		admi_pos->next = t;
		fread(t, sizeof(class Admini), 1, fp3);
		admi_pos = admi_pos->next;
	} while (admi_pos ->next!= NULL);
	  do
	{
		  ch = fgetc(fp4);
		  if (ch == EOF)break;
		Teacher_Experimenter* t = new(Teacher_Experimenter);
		teach_exper_pos->next = t;
		fread(t, sizeof(class Teacher_Experimenter), 1, fp4);
		teach_exper_pos = teach_exper_pos->next;
	} while (teach_exper_pos ->next!= NULL);
	  do
	{
		  ch = fgetc(fp5);
		  if (ch == EOF)break;
		Admini_Teacher* t = new Admini_Teacher;
		admi_teach_pos->next = t;
		fread(t, sizeof(class Admini_Teacher), 1, fp5);
		admi_teach_pos = admi_teach_pos->next;

	}while (admi_teach_pos ->next!= NULL);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	printf("读取完成!\n");
	system("pause");
	system("cls");
 }




	//主函数实现
int main() {
	
	teacher_head->next = nullptr;
	teacher_head->num = 0;
	exper_head->next = nullptr;
	exper_head->num = 0;
	admi_head->next = nullptr;
	admi_head->num = 0;
	teacher_head->next = nullptr;
	teacher_head->num = 0;
	admi_teach_head->next = nullptr;
	admi_teach_head->num = 0;
	//---------------------------接下来是实现函数------------------------------------------
	interface service;//定义一个interface的接口
	service.display();//实现函数
	return 0;
}
