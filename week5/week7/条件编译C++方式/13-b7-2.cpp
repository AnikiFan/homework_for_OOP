/* 2254298 大数据 范潇 */
#include <iostream>
/* --如果某编译器有需要，此处允许按条件编译的格式加入头文件 --*/

using namespace std;

int main()
{
	char a[80];

#if (***)||(***)  //DevC++
	gets(a);
#elif (***)       //VS2022
	gets_s(a);
#elif (***)       //Linux
	fgets(a, 80, stdin); //不需要处理最后的回车
#endif

	cout << a << endl;
	return 0;
}