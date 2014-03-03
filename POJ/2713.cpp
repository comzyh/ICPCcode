#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	char str[100];
	while(gets(str)!=NULL)
	{
		int a,b,c;
		sscanf(str,"%*s%d%*s%d%*[^0-9]%d",&a,&b,&c);
		printf("%s: %.0f\n",str,(a*b*2.0/1000.0+c*2.54)*acos(-1.0));
	}
	return 0;
}