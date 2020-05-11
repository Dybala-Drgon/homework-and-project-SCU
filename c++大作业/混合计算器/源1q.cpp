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
	friend complex operator /(const complex& t1, const complex& t2);//�ֱ�����Ԫ����ʵ�ֲ���������
};

void complex::print() {
	if(image>0)
	cout <<"="<< real << "+" << image << "i" << endl;
	else
	cout <<"="<< real << image << "i" << endl;
}
	//���ؼӷ�
complex operator+(const complex& t1, const complex& t2)
{
	return complex(t1.real+t2.real,t1.image+t2.image);
}
//���ؼ���
complex operator-(const complex& t1, const complex& t2)
{
	return complex(t1.real - t2.real, t1.image - t2.image);
}  
//���س˷�
complex operator*(const complex& t1, const complex& t2)
{
	return complex(t1.real*t2.real-t1.image*t2.image,t1.real*t2.image+t1.image*t2.real);
}	 
//���س���
complex operator/(const complex& t1, const complex& t2)
{
	double tem = t2.image * t2.image + t2.real * t2.real;
	complex t3(t2.real, -t2.image);//������ת����
	 t3 = t3 * t1;//����
	return complex(t3.real/tem,t3.image/tem);
}
//-----------------------------------------------------------------------
//������ʵ��ration��
class ration {
private:
	int denominator, numerator;
public:
	ration(int n=0,int d=1):denominator(d),numerator(n){}	 //��һ�������Ƿ���
	void print();
	ration operator +(const ration& t);
	ration operator -(const ration& t);
	ration operator *(const ration& t);
	ration operator /(const ration& t);//ʹ�ó�Ա����ʵ��+-*/
};
void ration::print() {//ʹ��շת��������������Լ��
	int rem;
	int n = denominator, m = numerator;
	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}
	//���Լ����m
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
  //ʵ�����----------------------------------------------------------------------------------------------
 //ʵ�ֽ�����
class view {
public:
	void com();
	void rat();
};

//���Դ��� ----------------main function--------------------------------
int main() {
	int select;
	for (;;) {
	 cout << "ѡ������ģʽ��1��������2����������3���˳�" << endl;
	 cin >> select;
	// fflush(stdin);//������̻���
	 view a;
	switch (select)
	{
	case 1:a.com();
		break;
	case 2:a.rat();
		break;
	case 3:return 0;
	default:
		cout << "�����������" << endl;
		break;
	}  
	//fflush(stdin);//������̻���
}
	

	return 0;
}//-------------------------------------------------------------------


void view::com() {
	for (;;) {
		double r1, i1, r2, i2;
		char key = '1';
		char n;
		cout << "��������������������ʽ��(a+bi)�����(a+bi)" << endl;
		getchar();
		scanf("(%lf%lfi)%c(%lf%lfi)", &r1, &i1, &n, &r2, &i2); //ʹ��scanf���Ƹ�ʽ
		//fflush(stdin);//������̻���
		complex t1(r1, i1);
		complex t2(r2, i2);	 //������������
		complex c;
		//fflush(stdin);//������̻���
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
		cout << "��0�˳�" << endl;
		getchar();
		scanf("%c", &key);
		//fflush(stdin);//������̻���
		if (key == '0')break;
	}
}
void view::rat() {
	for (;;) {
		int z1, m1, z2, m2;
		char key = '1'; char n;
		cout << "��������������������������/��ĸ˳��" << endl;
		scanf("%d/%d%c%d/%d", &z1, &m1, &n, &z2, &m2);
		fflush(stdin);//������̻���
		ration r1(z1, m1);
		ration r2(z2, m2);
		ration c;
		fflush(stdin);//������̻���
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
		cout << "��0�˳�" << endl;
		cin >> key;
		fflush(stdin);//������̻���
		if (key == '0')break;
	}
}

