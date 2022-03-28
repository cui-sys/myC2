#include <iostream>

using namespace std;
//变量名实质上是一段连续的内存空间别名，是一个标号（门牌号）程序中通过变量来申请并命名内存空间 通过变量名可以使用存储空间
#if 0
//【引用】给已有的变量取别名
//1、&和别名结合 表示引用
//2、给某个变量取别名 就定义某个变量
//3、从上往下替换
void test()
{
    int num = 10;
    int &a = num;//不是取地址而是表明 a 是 num的别名
    cout<<"a:"<<a<<endl;// a 完全等价 num

}

//类型标识符是指目标变量的类型。
//必须在声明时进行初始化。
//引用一旦初始化之后不能改变别名。
//不能有 NULL 引用。
void test()
{
    int num = 10;
    int &a = num;

    int date = 20;
    // int &a = date;//-err
    a = date;// 不是 date 别名为 a  而是 date 值赋值 a(num)
    cout<<"num："<<num<<endl;
    // a 是 num 的别名
    cout<<"a 的地址"<<&a<<endl;
    cout<<"num 的地址"<<&num<<endl;
    // 所以 num 和 a 具有相同的空间地址
}

//引用作用于【数组】 - 给【数组】取别名
//1、
void test()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    //需求：给 arr 取别名
    int (&my_arr)[5] =  arr;//给【数组】 arr 取别名 my_arr

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
//2、
void test2()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    // 1、用 typedef 给数组类型 取别名
    typedef int TYPE_ARR[5];//TYPE_ARR 是一个数组类型 （有 5 个元素 每个元素为 int）

    TYPE_ARR newArr = { 1, 2, 3, 4, 5 };
    TYPE_ARR &myArr = arr;// myArr 就是【数组】 arr 的别名

    int i = 0;
    for(i = 0; i < 5; i++ )
    {
        cout << myArr[i] <<" ";
    }
    cout << endl;
}

//函数中的【引用】
//引用作为函数的参数
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
void my_swap3(int &a, int &b)//取别名
{
    int tmp = a;
    a = b;
    b = tmp;
}

void test()
{
    int date1 = 10, date2 = 20;
    //cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
    //my_swap1(date1, date2);// 交换失败
    cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
    //my_swap2(&date1, &date2);//取地址可以交换成功
    //cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
    my_swap3(date1, date2);//取别名可以交换成功，不能与取地址解应用同时使用
    cout << "date1 = " << date1 <<", date2 = " << date2 <<endl;
}
#endif
// 引用作为函数的返回值
int& my_date1(void)
{
    int num = 10;
    return num;
    // 函数的返回值是引用时 不要返回局部变量
}
int &my_date2(void)
{
    static int num = 20;//静态存储 - 静态变量只被调用一次
    return num;// - OK
}
//当函数为【左值】 那么函数的返回值类型必须是【引用】
void test()
{
   //int &ret = my_date1();
   //cout << "ret : " << ret << endl;//非法访问内存 - 函数退出时函数内部局部变量的内存空间已释放
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
   //函数的返回值 作为左值
    my_date3() = 2000;
    my_date3();
}

int main(int argc, char *argv[])
{
    test1();
    return 0;
}
