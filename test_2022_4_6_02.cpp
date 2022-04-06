#include <iostream>
#include "test_2022_4_6_03.h"
using namespace std;
//【混合编程】
int main(int argc, char *argv[])
{
    cout <<my_add(100,200) << endl;
    cout <<my_sub(100,200) << endl;
    return 0;
}
//ubuntu 下
// test_2022_4_6_02.cpp  test_2022_4_6_03.c  test_2022_4_6_03.h
// 混合编译步骤：
// gcc -c test_2022_4_6_03.c -o test_2022_4_6_03.o
// g++ test_2022_4_6_02.cpp test_2022_4_6_03.o
