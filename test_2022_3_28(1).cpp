#include <iostream>

using namespace std;
//������ʵ������һ���������ڴ�ռ��������һ����ţ����ƺţ�������ͨ�����������벢�����ڴ�ռ� ͨ������������ʹ�ô洢�ռ�
#if 0
//�����á������еı���ȡ����
//1��&�ͱ������ ��ʾ����
//2����ĳ������ȡ���� �Ͷ���ĳ������
//3�����������滻
void test()
{
    int num = 10;
    int &a = num;//����ȡ��ַ���Ǳ��� a �� num�ı���
    cout<<"a:"<<a<<endl;// a ��ȫ�ȼ� num

}

//���ͱ�ʶ����ָĿ����������͡�
//����������ʱ���г�ʼ����
//����һ����ʼ��֮���ܸı������
//������ NULL ���á�
void test()
{
    int num = 10;
    int &a = num;

    int date = 20;
    // int &a = date;//-err
    a = date;// ���� date ����Ϊ a  ���� date ֵ��ֵ a(num)
    cout<<"num��"<<num<<endl;
    // a �� num �ı���
    cout<<"a �ĵ�ַ"<<&a<<endl;
    cout<<"num �ĵ�ַ"<<&num<<endl;
    // ���� num �� a ������ͬ�Ŀռ��ַ
}

//���������ڡ����顿 - �������顿ȡ����
//1��
void test()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    //���󣺸� arr ȡ����
    int (&my_arr)[5] =  arr;//�������顿 arr ȡ���� my_arr

    int i = 0;
    for(i = 0; i < 5; i++ )
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    int j = 0;
    for(j = 0; j < 5; j++)
    {
        cout << my_arr[j] << " ";
    }

}
//2��
void test2()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    // 1���� typedef ���������� ȡ����
    typedef int TYPE_ARR[5];//TYPE_ARR ��һ���������� ���� 5 ��Ԫ�� ÿ��Ԫ��Ϊ int��

    TYPE_ARR newArr = { 1, 2, 3, 4, 5 };
    TYPE_ARR &myArr = arr;// myArr ���ǡ����顿 arr �ı���

    int i = 0;
    for(i = 0; i < 5; i++ )
    {
        cout << myArr[i] <<" ";
    }
    cout << endl;
}

//�����еġ����á�
//������Ϊ�����Ĳ���
void my_swap1(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void my_swap2(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void my_swap3(int &a, int &b)//ȡ����
{
    int tmp = a;
    a = b;
    b = tmp;
}

void test()
{
    int date1 = 10, date2 = 20;
    //cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
    //my_swap1(date1, date2);// ����ʧ��
    cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
    //my_swap2(&date1, &date2);//ȡ��ַ���Խ����ɹ�
    //cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
    my_swap3(date1, date2);//ȡ�������Խ����ɹ���������ȡ��ַ��Ӧ��ͬʱʹ��
    cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
}
#endif
// ������Ϊ�����ķ���ֵ
int& my_date1(void)
{
    int num = 10;
    return num;
    // �����ķ���ֵ������ʱ ��Ҫ���ؾֲ�����
}
int &my_date2(void)
{
    static int num = 20;//��̬�洢 - ��̬����ֻ������һ��
    return num;// - OK
}
//������Ϊ����ֵ�� ��ô�����ķ���ֵ���ͱ����ǡ����á�
void test()
{
   //int &ret = my_date1();
   //cout << "ret : " << ret << endl;//�Ƿ������ڴ� - �����˳�ʱ�����ڲ��ֲ��������ڴ�ռ����ͷ�
   int &ret = my_date2();
   cout << "ret : " << ret << endl;
}
int &my_date3(void)
{
    static int num = 30;
    cout << "num = " << num << endl;
    return num;
}

void test1()
{
   //�����ķ���ֵ ��Ϊ��ֵ
    my_date3() = 2000;
    my_date3();
}

int main(int argc, char *argv[])
{
    test1();
    return 0;
}
