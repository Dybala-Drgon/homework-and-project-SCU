#include <iostream>
using namespace std;

template <class T>
class point_manager; //先申明一个管理类，用来管理point_like_class

template <class T>
class point_like_class //申明定义一个point_like_class,将指针封装成类
{
  private: //可以将所有成员全部申明为private，通过友元函数操作
    int reference_count; //用于记录引用的次数
    T *p;                //这是实际的指针
    point_like_class() : reference_count(0), p(0) {}       //无参构造函数
    point_like_class(T *px) : reference_count(1), p(px) {} //有参构造函数
    ~point_like_class();
    friend point_manager<T>; //指针管理友元

    //设置两个内联函数进行引用数的修正
    inline   void inc_count() { reference_count++;}              
    inline void dec_count() { reference_count--; }
    inline int get_count() const { return reference_count; } //返回引用数目
};

template <class T> class point_manager {
  private:
    point_like_class<T> *point; //指向指针类的指针
  public:
    point_manager(T *ptr);                    //有参构造函数
    point_manager(const point_manager<T> &t); //复制构造函数
    point_manager();                          //无参构造函数

    ~point_manager();
    inline int get_manager_count() { return point->get_count(); }//获得引用数
    T &operator*();  //重载解引用
    T *operator->(); //重载->
    point_manager & operator=(const point_manager<T> &); //重载=符号，注意左值右值关系
    point_manager & operator=(T *ptr); //重载=符号，注意左值右值关系
    T &operator[](int n); //重载[]，让他看起来更像一个指针
    T *operator+(int n); //重载加法符号，对应指针在数组上的移动
};

template <class T> point_like_class<T>::~point_like_class() {
    delete[] p; //单个元素也能通过delete []删除
    cout << "已经delete内存空间" << endl;
    p = 0; // p=0防止重复删除
}

template <class T>
point_manager<T>::point_manager(T *ptr) : point(new point_like_class<T>(ptr)) {}
//使用初始化列表初始化，用ptr作为point_like_class的内部指针p

template <class T> point_manager<T>::point_manager(const point_manager<T> &t) {
    point = t.point;
    point->inc_count(); //引用+1
}

template <class T> //默认无参构造函数
point_manager<T>::point_manager() {
    point = 0;
}

template <class T> T &point_manager<T>::operator*() {
    return *(point->p);
    //返回指针的解引用
}

template <class T> T *point_manager<T>::operator->() {
    return point->p;
    //返回实际指针
}

template <class T> point_manager<T>::~point_manager() {
    cout<<"析构manager"<<endl;
    if(point!=0){
    point->dec_count(); //减少了一个引用
    if (point->get_count() <= 0) {
        cout << "内存空间引用=0,delete point" << endl;
        delete point; //引用减到0时就delete掉
     }
    }
}

template <class T>
point_manager<T> &point_manager<T>::operator=(const point_manager<T> &t) {
    //参数作为右值，this作为左值

    t.point->inc_count();
    this->point->dec_count();
    //左值-1，右值+1

    if (point->get_count() <= 0) {
        //如果左值丢失
        cout << "左值丢失" << endl;
        delete point;
    }
    point = t.point;
    return *this;
}

template <class T> //重载等于的第二种情况
point_manager<T> &point_manager<T>::operator=(T *ptr) {
    if(point!=0){//如果一开始就没有分配内存，就直接跳到下一步
         point->dec_count();//减少一个引用
         if (point->get_count() <= 0) {
         //如果左值丢失
          cout << "左值丢失" << endl;
          delete point;
     }
    }
    point = new point_like_class<T>(ptr);//manager通过point_like_class指向新的内存空间
    return *this;
}

template <class T> //返回p[]的引用
T &point_manager<T>::operator[](int n) {
    return *((point->p) + n);
}

template <class T> T *point_manager<T>::operator+(int n) {
    return ((this->point->p) + n);
} //返回的是一个普通指针，不是一个manager

void fun(){
    point_manager<int>p(new int[33]);
}
int main() {
    fun();
    system("pause");
    return 0;
}
