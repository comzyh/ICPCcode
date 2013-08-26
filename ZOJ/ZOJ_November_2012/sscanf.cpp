#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
inline int find(char* src,char* tip)
{
	char t[300];
	for (int i=1,pos=0;sscanf(src+pos,"%s",t)!=EOF;pos+=strlen(t)+1,i++)
		if (strcmp(t,tip)==0)return i;
	return 0;
}
int main()
{
	char str1[300],str2[300]="aa bb cc dd ah haha hahaha";
	char t[30];
	int pos=0;
	printf("%d====\n",'z');
	cout << find(str1,"aa")<<endl;
	cout << find(str1,"bb")<<endl;
	cout << find(str1,"haha")<<endl;
	cout << find(str1,"asdasd")<<endl;
	memcpy(str1,str2,strlen(str2)+1);
	cout <<"-----"<<endl;
	cout <<str1<<endl;
	cout <<strcmp("aa","bb")<<endl;
}
