#include "staff.h"
#include<cstdio>
#include<iostream>
using namespace std;

void showinfo(staff* ptr) {
	ptr->show();
}	   //ʵ���麯������

void staff::Setinfo()
{
	cout << "����id" << endl;
	cin >> ID;
	getchar();//�Ե��س�
	cout << "����name" << endl;
	cin >> Name;
	getchar();
	cout << "�����������" << endl;
	cin >> Basic_salary;
	Salary_sum = Basic_salary;//����ְԱֻ�л�������
}//����ְԱ

void staff::show()
{
	cout << "ID\t\t" << "NAME\t" << "��������\t" << "�����ܺ�\t" <<"���"<< endl;
	//ʹ��printf�������
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
	cout << "ID\t" << "NAME\t" << "��������\t" << "�����ܺ�\t" <<"��ʱ����\t"<< "���" << endl;
	//ʹ��printf�������
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t�ον�ʦ\n", GetID(), GetName(),GetBasic_salary(),GetSalary_sum(),class_hour_salary );
}

void Teacher::Setinfo()
{
	staff::Setinfo();
	cout << "�����ʱ����" << endl;
	cin >> class_hour_salary;
	setsalary(GetBasic_salary(), class_hour_salary, 0, 0);
}

void Teacher::Setclass_hour_salary()
{
	cout << "��ʱ����" << endl;
	cin >> class_hour_salary;
}

double Teacher::get_class_hour_salary()
{
	return class_hour_salary;
}

void Experimenter::show()
{
	cout << "ID\t" << "NAME\t" << "��������\t" << "�����ܺ�\t" << "ʵ���Ҳ���\t" << "���" << endl;
	//ʹ��printf�������
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\tʵ��Ա\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), exper_subsidy);
}

void Experimenter::Setinfo()
{
	staff::Setinfo();
	cout << "ʵ���Ҳ���" << endl;
	cin >> exper_subsidy;
	setsalary(GetBasic_salary(), 0, exper_subsidy, 0);
}

void Experimenter::Setexper_subsidy()
{

	cout << "ʵ���Ҳ���" << endl;
	cin >> exper_subsidy;
}

double Experimenter::get_exper_subsidy()
{
	return exper_subsidy;
}

void Admini::show()
{
	cout << "ID\t" << "NAME\t" << "��������\t" << "�����ܺ�\t" << "��������\t" << "���" << endl;
	//ʹ��printf�������
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-8.2f\t������Ա\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), admin_subsidy);
}

void Admini::Setinfo()
{
	staff::Setinfo();
	cout << "��������" << endl;
	cin >> admin_subsidy;
	setsalary(GetBasic_salary(), 0, 0,admin_subsidy);
}

void Admini::Setadmin_subsidy()
{
	cout << "��������" << endl;
	cin >> admin_subsidy;
}

double Admini::get_admin_subsidy()
{
	return admin_subsidy;
}

void Teacher_Experimenter::show()
{
	cout << "ID\t" << "NAME\t" << "��������\t" << "�����ܺ�\t" << "��ʱ��ʵ�鲹��\t" << "  ���" << endl;
	//ʹ��printf�������
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-7.2f��%-7.2f ��ʦ��ʵ��Ա\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), get_class_hour_salary(),get_exper_subsidy());
 }

void Teacher_Experimenter::Setinfo()
{
	staff::Setinfo();
	Setexper_subsidy();
	Setclass_hour_salary();
	setsalary(GetBasic_salary(), get_class_hour_salary(), get_exper_subsidy(), 0);
}

void Admini_Teacher::show()
{
	cout << "ID\t" << "NAME\t" << "��������\t" << "�����ܺ�\t" << "��ʱ����������\t" << "  ���" << endl;
	//ʹ��printf�������
	printf("%-6s\t%s\t%-8.2f\t%-8.2f\t%-7.2f��%-7.2f ��ʦ��������Ա\n", GetID(), GetName(), GetBasic_salary(), GetSalary_sum(), get_class_hour_salary(), get_admin_subsidy());

}

void Admini_Teacher::Setinfo()
{
	staff::Setinfo();
	Setadmin_subsidy();
	Setclass_hour_salary();
	setsalary(GetBasic_salary(), get_class_hour_salary(), 0,get_admin_subsidy());

}
