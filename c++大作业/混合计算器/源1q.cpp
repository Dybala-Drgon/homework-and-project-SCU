#include<iostream>
#include<cstdio>
using namespace std;

class complex {
private:
	double real;
	double image;
public:
	complex(double r=0.0,double i=0.0):real(r),image(i){}
	void print();
	friend complex operator +(const complex& t1, const complex& t2);
	friend complex operator -(const complex& t1, const complex& t2);
	friend complex operator *(const complex& t1, const complex& t2);
	friend complex operator /(const complex& t1, const complex& t2);//分别用友元函数实现操作符重载
};

void complex::print() {
	if(image>0)
	cout <<"="<< real << "+" << image << "i" << endl;
	else
	cout <<"="<< real << image << "i" << endl;
}
	//重载加法
complex operator+(const complex& t1, const complex& t2)
{
	return complex(t1.real+t2.real,t1.image+t2.image);
}
//重载减法
complex operator-(const complex& t1, const complex& t2)
{
	return complex(t1.real - t2.real, t1.image - t2.image);
}  
//重载乘法
complex operator*(const complex& t1, const complex& t2)
{
	return complex(t1.real*t2.real-t1.image*t2.image,t1.real*t2.image+t1.image*t2.real);
}	 
//重载除法
complex operator/(const complex& t1, const complex& t2)
{
	double tem = t2.image * t2.image + t2.real * t2.real;
	complex t3(t2.real, -t2.image);//设置中转复数
	 t3 = t3 * t1;//分子
	return complex(t3.real/tem,t3.image/tem);
}
//-----------------------------------------------------------------------
//接下来实现ration类
class ration {
private:
	int denominator, numerator;
public:
	ration(int n=0,int d=1):denominator(d),numerator(n){}	 //第一个参数是分子
	void print();
	ration operator +(const ration& t);
	ration operator -(const ration& t);
	ration operator *(const ration& t);
	ration operator /(const ration& t);//使用成员函数实现+-*/
};
void ration::print() {//使用辗转相除法来计算最大公约数
	int rem;
	int n = denominator, m = numerator;
	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}
	//最大公约数是m
	denominator /= m;
	numerator /= m;
	cout << "="<<numerator << "/" << denominator << endl;
}

ration ration::operator+(const ration& t)
{
	return ration(this->numerator*t.denominator+t.numerator*this->denominator,this->denominator*t.denominator);
}

ration ration::operator-(const ration& t)
{
	return ration(this->numerator * t.denominator - t.numerator * this->denominator, this->denominator * t.denominator);
}

ration ration::operator*(const ration& t)
{
	return ration(t.numerator*this->numerator,t.denominator*this->denominator);
}

ration ration::operator/(const ration& t)
{
	return ration(t.denominator*this->numerator,this->denominator*t.numerator);
}
  //实现完毕----------------------------------------------------------------------------------------------
 //实现界面类
class view {
public:
	void com();
	void rat();
};

//测试代码 ----------------main function--------------------------------
int main() {
	int select;
	for (;;) {
	 cout << "选择运算模式，1：复数，2：有理数，3：退出" << endl;
	 cin >> select;
	// fflush(stdin);//清除键盘缓冲
	 view a;
	switch (select)
	{
	case 1:a.com();
		break;
	case 2:a.rat();
		break;
	case 3:return 0;
	default:
		cout << "输入错误，重试" << endl;
		break;
	}  
	//fflush(stdin);//清除键盘缓冲
}
	

	return 0;
}//-------------------------------------------------------------------


void view::com() {
	for (;;) {
		double r1, i1, r2, i2;
		char key = '1';
		char n;
		cout << "依次输入两个复数，格式：(a+bi)运算符(a+bi)" << endl;
		getchar();
		scanf("(%lf%lfi)%c(%lf%lfi)", &r1, &i1, &n, &r2, &i2); //使用scanf控制格式
		//fflush(stdin);//清除键盘缓冲
		complex t1(r1, i1);
		complex t2(r2, i2);	 //构造两个复数
		complex c;
		//fflush(stdin);//清除键盘缓存
		switch (n) {
		case '+':
			c = t1 + t2;
			c.print();
			break;

		case '-':
			c = t1 - t2;
			c.print();
			break;
		case '*':
			c = t1 * t2;
			c.print();
			break;
		case '/':
			c = t1 / t2;
			c.print();
			break;
		}
		cout << "按0退出" << endl;
		getchar();
		scanf("%c", &key);
		//fflush(stdin);//清除键盘缓存
		if (key == '0')break;
	}
}
void view::rat() {
	for (;;) {
		int z1, m1, z2, m2;
		char key = '1'; char n;
		cout << "依次输入两个有理数，按分子/分母顺序" << endl;
		scanf("%d/%d%c%d/%d", &z1, &m1, &n, &z2, &m2);
		fflush(stdin);//清除键盘缓冲
		ration r1(z1, m1);
		ration r2(z2, m2);
		ration c;
		fflush(stdin);//清除键盘缓存
		switch (n) {
		case '+':
			c = r1 + r2;
			c.print();
			break;
		case '-':
			c = r1 - r2;
			c.print();
			break;
		case '*':
			c = r1 * r2;
			c.print();
			break;
		case '/':
			c = r1 / r2;
			c.print();
			break;
		}
		cout << "按0退出" << endl;
		cin >> key;
		fflush(stdin);//清除键盘缓存
		if (key == '0')break;
	}
}

