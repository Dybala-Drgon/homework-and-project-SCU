#include "staff.h"
#include<cstdio>
#include<iostream>
using namespace std;



void staff::Setinfo()
{
	cout << "输入6位id" << endl;
	cin >> ID;
	getchar();//吃掉回车
	cout << "输入name" << endl;
	cin >> Name;
	getchar();
	cout << "输入基本工资" << endl;
	cin >> Basic_salary;
	Salary_sum = Basic_salary;//基础职员只有基本工资
}//设置职员

void staff::show()
{
	cout << "ID\t\t" << "NAME\t" << "基础工资\t" << "工资总和\t" <<"类别"<< endl;
	//使用printf方便输出
	printf("%-6s\t\t%s\t%-8.2f\t%-8.2f\t%s\n", ID, Name, Basic_salary, Salary_sum,pos);
}

char* staff::GetID()
{
	return ID;
}

char* staff::GetName()
{
	return Name;
}

inline double staff::GetBasic_salary() const
{
	return Basic_salary;
}

inline double staff::GetSalary_sum() const
{
	return Salary_sum;
}

void staff::setsalary(double basic, double classhour, double exper, double admin)
{
	Salary_sum = basic + classhour + exper+admin;
}

void Teacher::show()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" <<"课时补助\t"<< "类别" << endl;
	//使用printf方便输出
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t任课教师\n", GetID(), GetName(),GetBasic_salary(),GetSalary_sum(),class_hour_salary );
}

void Teacher::Setinfo()
{
	staff::Setinfo();
	Setclass_hour_salary();
	setsalary(GetBasic_salary(), class_hour_salary, 0, 0);
	getchar();//吃掉回车
}

void Teacher::Setclass_hour_salary()
{
	cout << "课时补助" << endl;
	cin >> class_hour_salary;
	
}

double Teacher::get_class_hour_salary()
{
	return class_hour_salary;
}

void Teacher::showall()
{
	
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t任课教师\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), class_hour_salary);
}

void Teacher::showmenu()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "课时补助\t" << "类别" << endl;
}

void Experimenter::show()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "实验室补助\t" << "类别" << endl;
	//使用printf方便输出
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t实验员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), exper_subsidy);
}

void Experimenter::Setinfo()
{
	staff::Setinfo();
	Setexper_subsidy();
	setsalary(GetBasic_salary(), 0, exper_subsidy, 0);
	getchar();//吃掉回车
}

void Experimenter::Setexper_subsidy()
{

	cout << "实验室补助" << endl;
	cin >> exper_subsidy;
}

double Experimenter::get_exper_subsidy()
{
	return exper_subsidy;
}

void Experimenter::showall()
{
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t实验员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), exper_subsidy);
}

void Experimenter::showmenu()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "实验室补助\t" << "类别" << endl;
}

void Admini::show()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "行政补助\t" << "类别" << endl;
	//使用printf方便输出
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t行政人员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), admin_subsidy);
}

void Admini::Setinfo()
{
	staff::Setinfo();
	Setadmin_subsidy();
	setsalary(GetBasic_salary(), 0, 0,admin_subsidy);
	getchar();//吃掉回车
}

void Admini::Setadmin_subsidy()
{
	cout << "行政补助" << endl;
	cin >> admin_subsidy;
}

double Admini::get_admin_subsidy()
{
	return admin_subsidy;
}

void Admini::showall()
{
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t行政人员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), admin_subsidy);
}

void Admini::showmenu()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "行政补助\t" << "类别" << endl;
}

void Teacher_Experimenter::show()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "课时和实验补助\t" << "  类别" << endl;
	//使用printf方便输出
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-7.2f和%-7.2f 教师兼实验员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), get_class_hour_salary(),get_exper_subsidy());
 }

void Teacher_Experimenter::Setinfo()
{
	staff::Setinfo();
	Setexper_subsidy();
	Setclass_hour_salary();
	setsalary(GetBasic_salary(), get_class_hour_salary(), get_exper_subsidy(), 0);
	getchar();//吃掉回车
}

void Teacher_Experimenter::showall()
{
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-7.2f和%-7.2f 教师兼实验员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), get_class_hour_salary(), get_exper_subsidy());
}

void Teacher_Experimenter::showmenu()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "课时和实验补助\t" << "  类别" << endl;
}

void Admini_Teacher::show()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "课时和行政补助\t" << "  类别" << endl;
	//使用printf方便输出
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-7.2f和%-7.2f 教师兼行政人员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), get_class_hour_salary(), get_admin_subsidy());

}

void Admini_Teacher::Setinfo()
{
	staff::Setinfo();
	Setadmin_subsidy();
	Setclass_hour_salary();
	setsalary(GetBasic_salary(), get_class_hour_salary(), 0,get_admin_subsidy());
	getchar();//吃掉回车

}

void Admini_Teacher::showall()
{
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-7.2f和%-7.2f 教师兼行政人员\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), get_class_hour_salary(), get_admin_subsidy());
}

void Admini_Teacher::showmenu()
{
	cout << "ID\t" << "NAME\t" << "基础工资\t" << "工资总和\t" << "课时和行政补助\t" << "  类别" << endl;
}

void showinfo(staff* ptr)
{
	
		ptr->show();
	
}

