// const 修饰的全局变量 默认是内部链接（只在当前源文件有效，不能直接用于其他源文件）
//const int date = 10;

//如果必须用在其他源文件 使用只读的全局变量 必须在前加 extern 转换成外部链接
extern const int date = 10;
