#include <iostream>
#include <cstring>
using namespace std;
struct TT
{
	int a,b,c;
	TT()
	{
		a=0;
		b=0;
		c++;
		cout << c <<endl;
	}
	void print()
	{
		cout <<a <<' '<<b << ' '<< c <<endl;
		*this=TT();
	}
	
};
int main()
{
	TT a;
	while (1)
	{
		a.c=0;
		a.print();
		getchar();
	}
}
