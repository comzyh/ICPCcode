#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int pos;
	while (getline(cin,str))
	{
		pos=0;
		while (pos=str.find("you",pos),pos!=-1)
			str.replace(pos,3,"we");
		cout <<str<<endl;
	}
}
