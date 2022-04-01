#include <iostream>

using namespace std;
//【内联函数 inline】
//预处理不允许访问类的成员函数 - 预处理器不能作为类的成员函数
//
#if 0
#define ADD(x,y) x+y //宏 - 保证不了参数的完整性
inline int Add(int x, int y)//内联函数
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
