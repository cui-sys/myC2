#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//���õı�����ָ��
#if 0
//ָ�������
void my_str(char** p_str)//p_str = &str
{
    //*p_str == *&str == str
    *p_str = (char*)calloc(1,32);
    strcpy(*p_str, "hello world");
    return ;
}
void my_str2(char* &my_str)//char* &my_str = str; my_str �ȼ� str
{
   my_str = (char*)calloc(1,32);//���ٿռ�
   strcpy(my_str, "hello world");
   return;
}
void test()
{
    char* str = NULL;
    //���󣺷�װ һ������ �Ӷ��� ��str����һ���ռ�  ����ֵΪ"hello world"
    //my_str(&str);
    my_str2(str);
    cout << "str = " << str << endl;
    free(str);//�ͷ��ڴ�
}


//��������
typedef struct
{
    int num;
    char name[32];
}Stu;

void myPrintStu(Stu stu)//��ͨ�ṹ�������Ϊ�β� �ڴ濪��̫��
{
    cout << "num = " << stu.num << ", name:" << stu.name << endl;
}

void myPrintStu2(const Stu &stu)//Sut &stu = dive; stu �� ����ʵ�� �ı��� - �����ÿ��Լ��Ϳռ俪����
{
    //stu.num = 2000;//����(�������ÿ��ܵ���ʵ�����βθı���ı�) - �β�ǰ�� const ���Խ�� const ���������ǲ��ܱ��޸ĵ�
    //strcpy(stu.name,"master");
    cout << "num = " << stu.num << ", name:" << stu.name << endl;
}

void test()
{
    Stu lucy = { 100, "lucy" };
    Stu dive = { 200, "dive" };
    //cout << "num = " << lucy.num << ", name : " << lucy.name << endl;
    //����һ���ṹ���Ա
    myPrintStu2(dive);
}

void test()
{
    //������ 10 ȡ������ num
    //int &��Ե���int - 10 �� const int ���� - ���Ͳ�һ��
    const int &num = 10;//-err ��� - ǰ�߼� const

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
