#pragma once
class staff	   //��ְͨԱ��
{
private:
	char ID[6];
	char Name[21];
	double Basic_salary;
	double Salary_sum;
	char pos[10] = { "��ְͨԱ" };
public:
	void Setinfo();
	virtual void show();//�����麯��
	char* GetID();
	char* GetName();	
	inline
		double GetBasic_salary()const;
	inline
		double GetSalary_sum()const;	//���ó�����������ʡ�ռ�
	void setsalary(double basic, double classhour, double exper, double admin);		 //����н��

};
	 


//���ǽ�ʦ��	ʹ�������̳�
class Teacher :virtual public staff {	 
public:
	 virtual void show();//�����麯����ʵ�ֶ�̬
	 void Setinfo();	//��д������ʵ�ֶ�̬
	 void Setclass_hour_salary();
	 double get_class_hour_salary();
private: 
	double class_hour_salary;//��ʱ����
	 char pos[10] = { "�ον�ʦ" };
};	  

//����ʵ��Ա��	   �����̳�
class Experimenter :virtual public staff {
public:
	virtual void show();//�����麯����ʵ�ֶ�̬
	void Setinfo();		//��д������ʵ�ֶ�̬
	void Setexper_subsidy();
	double get_exper_subsidy();
private:
	double exper_subsidy;//ʵ���Ҳ���
	char pos[10] = { "ʵ��Ա" };
};

//����������Ա��	 �����̳�
class Admini :virtual public staff {
public:
	virtual void show();//�����麯����ʵ�ֶ�̬
	void Setinfo();		//��д������ʵ�ֶ�̬
	void Setadmin_subsidy();
	double get_admin_subsidy();
private:
	double admin_subsidy;//��������
	char pos[10] = { "������Ա" };
};

class Teacher_Experimenter :public Teacher, public Experimenter {
public:
	void show();   //ûдvirtualҲĬ����virtual����
	void Setinfo();
	
};

class Admini_Teacher :public Teacher, public Admini {
public:
	void show();   //ûдvirtualҲĬ����virtual����
	void Setinfo();
};