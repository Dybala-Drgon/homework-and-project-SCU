#include <cstdio>
#include <iostream>
using namespace std;

class complex {
  private:
    double real;
    double image;

  public:
    complex(double r = 0.0, double i = 0.0) : real(r), image(i) {}
    void print();
    friend complex operator+(const complex &t1, const complex &t2);
    friend complex operator-(const complex &t1, const complex &t2);
    friend complex operator*(const complex &t1, const complex &t2);
    friend complex operator/(const complex &t1, const complex &t2); //分别用友元函数实现操作符重载
};

void complex::print() {
    if (image > 0)
        cout << "=" << real << "+" << image << "i" << endl;
    else
        cout << "=" << real << image << "i" << endl;
}
//重载加法
complex operator+(const complex &t1, const complex &t2) {
    return complex(t1.real + t2.real, t1.image + t2.image);
}
//重载减法
complex operator-(const complex &t1, const complex &t2) {
    return complex(t1.real - t2.real, t1.image - t2.image);
}
//重载乘法
complex operator*(const complex &t1, const complex &t2) {
    return complex(t1.real * t2.real - t1.image * t2.image,
                   t1.real * t2.image + t1.image * t2.real);
}
//重载除法
complex operator/(const complex &t1, const complex &t2) {
    double tem = t2.image * t2.image + t2.real * t2.real;
    complex t3(t2.real, -t2.image); //设置中转复数
    t3 = t3 * t1;                   //分子
    return complex(t3.real / tem, t3.image / tem);
}
//-----------------------------------------------------------------------
//接下来实现ration类
class ration {
  private:
    int denominator, numerator;
    double value;

  public:
    ration(int n = 0, int d = 1)
        : denominator(d), numerator(n) {} //第一个参数是分子
    void print();
    void optimization();
    void real();
    ration operator+(const ration &t);
    ration operator-(const ration &t);
    ration operator*(const ration &t);
    ration operator/(const ration &t); //使用成员函数实现+-*/
};

void ration::optimization(){
    //使用辗转相除法来计算最大公约数
    int rem;
    int n = denominator, m = numerator;
    if (n < 0)
        n = -n;
    if (m < 0)
        m = -m;
    while (n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    //最大公约数是m
    denominator /= m;
    numerator /= m;
    if(denominator<0&&numerator<0){
        denominator=-denominator;
        numerator=-numerator;
    }
}

void ration::real(){
    value=double(numerator)/double(denominator);
}

void ration::print() { 
    if (denominator!=0)
    cout << "=" << numerator << "/" << denominator <<"="<<value <<endl;
    else 
    cout<<"分母为0"<<endl;
}

ration ration::operator+(const ration &t) {
    return ration(this->numerator * t.denominator +
                      t.numerator * this->denominator,
                  this->denominator * t.denominator);
}

ration ration::operator-(const ration &t) {
    return ration(this->numerator * t.denominator -
                      t.numerator * this->denominator,
                  this->denominator * t.denominator);
}

ration ration::operator*(const ration &t) {
    return ration(t.numerator * this->numerator,
                  t.denominator * this->denominator);
}

ration ration::operator/(const ration &t) {
    return ration(t.denominator * this->numerator,
                  this->denominator * t.numerator);
}
//实现完毕----------------------------------------------------------------------------------------------
//实现界面类
class view {
  public:
    void com();
    void rat();
    void menu();
};

//测试代码 ----------------main function--------------------------------
int main() {
    view interface;
    interface.menu();
    return 0;
}

//-------------------------------------------------------------------
void view::menu() {
    int select;
    for (;;) {
        cout << "选择运算模式，1：复数，2：有理数，3：退出" << endl;
        cin >> select;
        getchar(); //吃掉回车
        view a;
        switch (select) {
        case 1:
            com();
            break;
        case 2:
            rat();
            break;
        case 3:
            return;
        default:
            cout << "输入错误，重试" << endl;
            break;
        }
    }
}

void view::com() {
    for (;;) {
        double r1, i1, r2, i2;
        char key = '1';
        char n;
        cout << "依次输入两个复数，格式：(a+bi)运算符(a+bi)" << endl;
        scanf("(%lf%lfi)%c(%lf%lfi)", &r1, &i1, &n, &r2,
              &i2); //使用scanf控制格式
        getchar();
        complex t1(r1, i1);
        complex t2(r2, i2); //构造两个复数
        complex c;
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
        scanf("%c", &key);
        getchar();
        if (key == '0') {
            system("cls");
            break;
        }
    }
}
void view::rat() {
    for (;;) {
        int z1, m1, z2, m2;
        char key = '1';
        char n;
        cout << "依次输入两个有理数，按分子/分母 操作符 分子/分母顺序" << endl;
        scanf("%d/%d%c%d/%d", &z1, &m1, &n, &z2, &m2);
        getchar();
        ration r1(z1, m1);
        ration r2(z2, m2);
        ration c;
        fflush(stdin); //清除键盘缓存
        switch (n) {
        case '+':
            c = r1 + r2;
            break;
        case '-':
            c = r1 - r2;
            break;
        case '*':
            c = r1 * r2;
            break;
        case '/':
            c = r1 / r2;
            break;
        }
        c.optimization();
        c.real();
        c.print();
        cout << "按0退出" << endl;
        cin >> key;
        getchar();
        if (key == '0') {
            system("cls");
            break;
        }
    }
}
