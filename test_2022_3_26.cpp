#include <iostream>

using namespace std;
#if 0
//���� bool ���͹ؼ��� - ture\false(�� 0 ֵ���Զ�תΪ ture(1),0 ֵ���Զ�תΪ false(0))
void test1()
{
	bool mybool;
	cout << "sizedf(bool) = " << sizeof(bool) << endl;//1�ֽڴ��
	mybool = false;
	cout << "myfalse = " << false << endl;
}

//��Ŀ�����������ǿ -��a > b ? a : b��//c�������������� ��ֵ�����ܱ�������
//void test2()
//{
//	int a = 10;
//	int b = 20;
//	printf("c���ԣ�%d\n", a > b ? a : b);//20
//  //��a > b ? a : b��= 100; - err	����ֵ����Ϊ��ֵ
//}
// c������Ŀ������ʽ����ֵΪ����ֵ��Ϊ��ֵ�����ܸ�ֵ��
// c++������Ŀ���ʽ����ֵΪ�����������ã���Ϊ��ֵ�����Ը�ֵ
void test1()
{
	int a = 10;
	int b = 20;
	cout << "c++ %d:" << (a > b ? a : b) << endl;
	//(a > b ? a : b)�������Ǳ����������ã� ��ֵ ���ܱ���ֵ - �ܱ���ֵ�ľ�����ֵ�����ܱ���ֵ�ľ�����ֵ��
	a > b ? a : b = 100;
	cout << "c++ %d:" << (a > b ? a : b) << endl;
}

// c/c++ �е� const �ؼ��֣���һ���޶����������޶�һ�������������ı䣬��һ������ת����һ������
//�� c ��
//const ���ε�ȫ�ֱ���ʱ�����ֳ����� - �ڴ�ռ���ֻ���ģ� Ĭ���ǣ��ⲿ���ӵ� - ����Դ�ļ�����ʹ�� - ʹ��ʱ����Ҫ�������� - "extern const int num;"��- ����ͨ���ڴ�ռ��ַ�޸�����
//const int a = 100;//һ�����ܱ��ı����ͨ���� - ֻ������(���ǿ���ͨ����ַ����޸�����Ӧ�ڴ�ռ������ - "int* p = (int*)data; *p = 2000;" - �ֲ�ֻ��������ջ�� - �ڴ�ɶ���д��)
//a = 100;// - err
//�� c++ ��
//const ����ȫ�ֱ�����Ĭ���ڲ����ӣ�ֻ�ڵ�ǰ�ļ�����Ч��
extern const int num;

//�� c++ �г��������к����� const �����������ļ��������ļ��в��ɼ�����Ĭ��Ϊ�ڲ����ӣ�c++ ��������ʶ��һ��Ĭ��Ϊ�ⲿ���ӡ�
void test1()
{	
	//�� c++ ��һ�� const ���ش����ڴ�ռ�
	cout << "ȫ��num = " << num << endl; 	
}

//c++ �� const ���εľֲ�����1
void test1()
{
	//�� c++ ��һ�� const ���ش����ڴ�ռ� 
	const int date = 10;// date ���Կ��ɳ��������� #define date 10��
	cout << "date:" << date << endl;
	//date = 100;//-err
	//���� date ��ȡ��ַ��ʱ�� ϵͳ�Ż�� date ���ٿռ�
	int* p = (int*)&date;
	*p = 2000;
	cout << "*p = " << *p << endl;//�ռ�������	
	cout << "date = " << date << endl;// date ��ֵ���ŵ��˷��ű��ж������ڴ�ռ���	
}
#endif
//c++ �� const ���εľֲ�����2
//�����һ��������ʼ�� const ����"const int a = b;"����ϵͳҲ��� "a" �����ڴ�

void test1()
{
	int b = 10;
	const int a = b;//ϵͳ��Ϊ a ֱ�ӿ��ٿռ������ŵ����ű���
	cout << "a: " << a << endl;

	int* p = (int*)&a;
	*p = 300;
	cout << "*p: " << *p << endl;
	cout << "a: " << a << endl;
}
int main(int argc, char* argv[])
{
	test1();

	return 0;
}