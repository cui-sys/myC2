#include <iostream>

using namespace std;
//���������� inline��
//Ԥ�������������ĳ�Ա���� - Ԥ������������Ϊ��ĳ�Ա����
//
#if 0
#define ADD(x,y) x+y //�� - ��֤���˲�����������
inline int Add(int x, int y)//��������
{
    return x+y;
}
void test()
{
    int ret = ADD(10,20)*10;
    int sum = Add(10,20)*10;
    cout<<"ret:"<<ret<<endl;
    cout<<"sum:"<<sum<<endl;
}
#endif
#define COMPARE(X,Y) ((X)<(Y)?(X):(Y))
int Compare(int x, int y){
    return x<y?x:y;
}

void test(){
    int a = 1;
    int b = 3;
    cout<<"COMPARE:"<<COMPARE(++a,b)<<endl;
    cout<<"Compare:"<<Compare(++a,b)<<endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
