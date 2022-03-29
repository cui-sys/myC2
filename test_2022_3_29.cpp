#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//引用的本质是指针
#if 0
//指针的引用
void my_str(char** p_str)//p_str = &str
{
    //*p_str == *&str == str
    *p_str = (char*)calloc(1,32);
    strcpy(*p_str, "hello world");
    return ;
}
void my_str2(char* &my_str)//char* &my_str = str; my_str 等价 str
{
   my_str = (char*)calloc(1,32);//开辟空间
   strcpy(my_str, "hello world");
   return;
}
void test()
{
    char* str = NULL;
    //需求：封装 一个函数 从堆区 给str申请一个空间  并赋值为"hello world"
    //my_str(&str);
    my_str2(str);
    cout << "str = " << str << endl;
    free(str);//释放内存
}


//常量引用
typedef struct
{
    int num;
    char name[32];
}Stu;

void myPrintStu(Stu stu)//普通结构体变量作为形参 内存开销太大
{
    cout << "num = " << stu.num << ", name:" << stu.name << endl;
}

void myPrintStu2(const Stu &stu)//Sut &stu = dive; stu 是 被传实参 的别名 - 【引用可以减低空间开销】
{
    //stu.num = 2000;//风险(由于引用可能导致实参随形参改变而改变) - 形参前加 const 可以解决 const 修饰引用是不能被修改的
    //strcpy(stu.name,"master");
    cout << "num = " << stu.num << ", name:" << stu.name << endl;
}

void test()
{
    Stu lucy = { 100, "lucy" };
    Stu dive = { 200, "dive" };
    //cout << "num = " << lucy.num << ", name : " << lucy.name << endl;
    //便利一个结构体成员
    myPrintStu2(dive);
}

void test()
{
    //给常量 10 取个别名 num
    //int &针对的是int - 10 是 const int 类型 - 类型不一致
    const int &num = 10;//-err 解决 - 前边加 const

    cout << " num = "<<num<<endl;
}
#endif
void test()
{

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
