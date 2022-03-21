#include <iostream>

using namespace std;
int a = 10;//全局变量
void test()
{
    int a =20;//局部变量（）
    cout<<"a="<<a<<endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
