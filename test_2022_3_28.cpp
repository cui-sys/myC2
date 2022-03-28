#include <iostream>
using namespace std;
void test1(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void test2(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int tabe1 = 10, tabe2 = 20;

    /*test1(&tabe1, &tabe2);
    cout << "tabe1 = " << tabe1 << ", tabe2 = " << tabe2 << endl;*/
    test2(tabe1, tabe2);
    cout << "tabe1 = " << tabe1 << ", tabe2 = " << tabe2 << endl;

    return 0;
}