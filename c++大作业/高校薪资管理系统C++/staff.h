#pragma once
class staff	   //普通职员类
{
private:
	char ID[6];
	char Name[21];
	double Basic_salary;
	double Salary_sum;
	char pos[10] = { "普通职员" };
public:									
	void Setinfo();
	virtual void show();//设置虚函数
	char* GetID();
	char* GetName();	
	inline
		double GetBasic_salary()const;
	inline
		double GetSalary_sum()const;	//设置成内联函数节省空间
	void setsalary(double basic, double classhour, double exper, double admin);		 //计算薪资
	staff* next;//使用链表进行增删改查
	int num;//总数
};
	 


//这是教师类	使用虚基类继承
class Teacher :virtual public staff {	 
public:
	 virtual void show();//设置虚函数，实现多态
	 void Setinfo();	//重写函数，实现多态
	 void Setclass_hour_salary();
	 double get_class_hour_salary();
	 Teacher* next;//使用链表进行增删改查
	 int num;//总数
	 Teacher() { next = nullptr; }
private: 
	double class_hour_salary;//课时补助
	 char pos[10] = { "任课教师" };
};	  

//这是实验员类	   虚基类继承
class Experimenter :virtual public staff {
public:
	virtual void show();//设置虚函数，实现多态
	void Setinfo();		//重写函数，实现多态
	void Setexper_subsidy();
	double get_exper_subsidy();
	int num;//总数
	Experimenter* next;//使用链表进行增删改查
	Experimenter() { next = nullptr; }
private:
	double exper_subsidy;//实验室补助
	char pos[10] = { "实验员" };
};

//这是行政人员类	 虚基类继承
class Admini :virtual public staff {
public:
	virtual void show();//设置虚函数，实现多态
	void Setinfo();		//重写函数，实现多态
	void Setadmin_subsidy();
	double get_admin_subsidy();
	Admini* next;//使用链表进行增删改查
	int num;//总数
	Admini() { next = nullptr; }
private:
	double admin_subsidy;//行政补助
	char pos[10] = { "行政人员" };
};

class Teacher_Experimenter :public Teacher, public Experimenter {
public:
	void show();   //没写virtual也默认是virtual类型
	void Setinfo();
	Teacher_Experimenter* next;//使用链表进行增删改查
	int num;//总数
	Teacher_Experimenter() { next = nullptr; }
};

class Admini_Teacher :public Teacher, public Admini {
public:
	void show();   //没写virtual也默认是virtual类型
	void Setinfo();
	Admini_Teacher* next;//使用链表进行增删改查
	Admini_Teacher() { next = nullptr; }
	int num;//总数
};

void showinfo(staff* ptr); 	   //实现虚函数作用
