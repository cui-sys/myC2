#include <iostream>
#include "data_2022_4_7_02.h"
using namespace std;
#if 0

//�������չ��
//��Ŀռ��С
class Data
{
private:
    //��Ա���� ռ��Ŀռ��С
    int num;//4Byt
public:
    //��Ա���� ��ռ��Ŀռ��С
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
    cout<<"Data��Ŀռ��С:"<<sizeof(Data)<<endl;
}

//������������ ���ⶨ��-��Ա������
class Data
{
private:
    //��Ա���� ռ��Ŀռ��С
    int num;//4Byt
public:
    //��Ա���� ������ ���� ���ⶨ��
    void setNum(int data);
    int getNum(void);

};
//Data ��ĳ�Ա����
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
    cout<<"Data��Ŀռ��С:"<<sizeof(Data)<<endl;

    Data ob;
    ob.setNum(100);
    cout<<"num = "<<ob.getNum()<<endl;
}
#endif

//����Ķ�����ͷ�ļ� ��Ա������cpp�ļ���ʵ�֡�
//���ļ�ʵ����
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
