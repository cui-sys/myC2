#include <iostream>

using namespace std;
#if 0
//新增 bool 类型关键字 - ture\false(非 0 值会自动转为 ture(1),0 值会自动转为 false(0))
void test1()
{
	bool mybool;
	cout << "sizedf(bool) = " << sizeof(bool) << endl;//1字节存放
	mybool = false;
	cout << "myfalse = " << false << endl;
}

//三目运算符的自曾强 -（a > b ? a : b）//c语言中整体结果是 右值（不能被操作）
//void test2()
//{
//	int a = 10;
//	int b = 20;
//	printf("c语言：%d\n", a > b ? a : b);//20
//  //（a > b ? a : b）= 100; - err	返回值不能为左值
//}
// c语言三目运算表达式返回值为数据值，为右值，不能赋值。
// c++语言三目表达式返回值为变量本身（引用），为左值，可以赋值
void test1()
{
	int a = 10;
	int b = 20;
	cout << "c++ %d:" << (a > b ? a : b) << endl;
	//(a > b ? a : b)整体结果是变量本身（引用） 左值 （能被赋值 - 能被赋值的就是左值，不能被赋值的就是右值）
	a > b ? a : b = 100;
	cout << "c++ %d:" << (a > b ? a : b) << endl;
}

// c/c++ 中的 const 关键字，是一个限定符，用来限定一个变量不允许被改变，将一个对象转换成一个常量
//在 c 中
//const 修饰的全局变量时（文字常量区 - 内存空间是只读的） 默认是（外部链接的 - 其他源文件可以使用 - 使用时必须要进行声明 - "extern const int num;"）- 不能通过内存空间地址修改内容
//const int a = 100;//一个不能被改变的普通变量 - 只读变量(但是可以通过地址间接修改所对应内存空间的内容 - "int* p = (int*)data; *p = 2000;" - 局部只读变量（栈区 - 内存可读可写）)
//a = 100;// - err
//在 c++ 中
//const 修饰全局变量，默认内部链接（只在当前文件内有效）
extern const int num;

//在 c++ 中出现在所有函数的 const 作用于整个文件（其他文件中不可见），默认为内部链接，c++ 中其他标识符一般默认为外部链接。
void test1()
{	
	//在 c++ 中一个 const 不必创建内存空间
	cout << "全局num = " << num << endl; 	
}

//c++ 中 const 修饰的局部变量1
void test1()
{
	//在 c++ 中一个 const 不必创建内存空间 
	const int date = 10;// date 可以看成常量（类似 #define date 10）
	cout << "date:" << date << endl;
	//date = 100;//-err
	//当对 date 在取地址的时候 系统才会给 date 开辟空间
	int* p = (int*)&date;
	*p = 2000;
	cout << "*p = " << *p << endl;//空间内容修	
	cout << "date = " << date << endl;// date 的值被放到了符号表中而不是内存空间中	
}
#endif
//c++ 中 const 修饰的局部变量2
//如果用一个变量初始化 const 变量"const int a = b;"这是系统也会个 "a" 分配内存

void test1()
{
	int b = 10;
	const int a = b;//系统会为 a 直接开辟空间而不会放到符号表中
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