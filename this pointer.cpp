#include <iostream>
using namespace std;
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	//p->Show();       //第一句代码
	//p->PrintA();     //第二句代码
}
