#include <iostream>
#include "data_2022_4_7_02.h"
using namespace std;
#if 0

//【类的扩展】
//类的空间大小
class Data
{
private:
    //成员数据 占类的空间大小
    int num;//4Byt
public:
    //成员函数 不占类的空间大小
    void setNum(int data)
    {
        num = data;
    }
    int getNum(void)
    {
        return num;
    }
};

void test()
{
    printf("%d\n",sizeof(Data));
    cout<<"Data类的空间大小:"<<sizeof(Data)<<endl;
}

//【在类内声明 类外定义-成员函数】
class Data
{
private:
    //成员数据 占类的空间大小
    int num;//4Byt
public:
    //成员函数 在类内 声明 类外定义
    void setNum(int data);
    int getNum(void);

};
//Data 类的成员函数
void Data::setNum(int data)
{
    num = data;
}
int Data::getNum(void)
{
    return num;
}

void test()
{
    cout<<"Data类的空间大小:"<<sizeof(Data)<<endl;

    Data ob;
    ob.setNum(100);
    cout<<"num = "<<ob.getNum()<<endl;
}
#endif

//【类的定义在头文件 成员函数在cpp文件中实现】
//分文件实现类
void test()
{
    Data ob;
    ob.setNum(135);
    cout<<"num = "<<ob.getNum()<<endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
